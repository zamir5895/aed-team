#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int pares(vector<int> nums, int K) {
        // HashTable, count
        // Key: num, Value: count
        unordered_map<int, int> hash;
        int count = 0;

        for (int num : nums) {
            // Complemento
            int complement = K - num;
            if (hash.find(complement) != hash.end()) {
                // If find complement, sum count
                count += hash[complement];
            }
            hash[num]++;
        }

        return count;
    }
};