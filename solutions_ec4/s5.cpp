class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        std::stack<int> maxs;
        int minimo = INT_MIN;
        for(int i = nums.size() -1; i >= 0; --i){
            if(nums.size() < 3){
                return false;
            }
            if(nums[i] < minimo){
                return true;
            }while(!maxs.empty() && nums[i] > maxs.top()){
                minimo = maxs.top();
                maxs.pop();
            }
            maxs.push(nums[i]);
        }
        return false;
    }
};