#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;

        for(const auto& prereq : prerequisites) {
            int from = prereq[1];
            int to = prereq[0];

            if(graph.find(from) == graph.end()) {
                graph[from] = vector<int>();
            }

            if(graph.find(to) == graph.end()) {
                graph[to] = vector<int>();
            }

            graph[from].push_back(to);
        }

        unordered_set<int> visited;

        for(const auto& entry : graph) {
            int node = entry.first;
            if (!dfs(graph, node, visited)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& graph, int curr, unordered_set<int>& visited) {
        if (visited.count(curr)) return false;

        if (graph[curr].empty()) return true;

        visited.insert(curr);

        for (int nei : graph[curr]) {
            if (!dfs(graph, nei, visited)) return false;
        }

        visited.erase(curr);
        graph[curr].clear();

        return true;
    }
};