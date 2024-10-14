#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int from = pre[1];
            int to = pre[0];

            indegree[to] += 1;

            if (graph.find(from) == graph.end()) {
                graph[from] = vector<int>();
            }

            if (graph.find(to) == graph.end()) {
                graph[to] = vector<int>();
            }

            graph[from].push_back(to);
        }

        queue<int> cola;
        for (int i = 0; i <= numCourses - 1; i++) {
            if (indegree[i] == 0) {
                cola.push(i);
            }
        }

        int processed = 0;
        while (!cola.empty()) {
            int course = cola.front();
            cola.pop();

            processed += 1;

            for (const auto& nei : graph[course]) {
                indegree[nei] -= 1;
                if (indegree[nei] == 0) {
                    cola.push(nei);
                }
            }
        }

        return processed == numCourses;
    }
};