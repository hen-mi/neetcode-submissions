class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> maxStack;

        for(int i = 0; i != temperatures.size(); ++i) {


            while(!maxStack.empty() &&  temperatures[maxStack.top()]< temperatures[i]) {

                ans[maxStack.top()] = i - maxStack.top();
                maxStack.pop();


            }


            maxStack.push(i);
        }

        return ans;
    }
};
