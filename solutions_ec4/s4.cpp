class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int j = 0;

        for(int i=0; i < pushed.size(); i++){
            stack.push(pushed[i]);

            while (!stack.empty() && stack.top() == popped[j]){
                stack.pop();
                ++j;
            }
        }
        return j == popped.size();
    }
};