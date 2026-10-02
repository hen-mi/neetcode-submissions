class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stack;
        int rect = 0;
        int start = 0;
        for(int i = 0; i != heights.size(); ++i) {
            
            start = i;

            while(!stack.empty() && heights[i] < stack.top().second) {

                pair<int, int> temp = stack.top();

                int index = temp.first;
                int val = temp.second;


                
                rect = max(rect, val * (i - index));

                start = index;
                stack.pop();


            }

            stack.push({start, heights[i]});
        }

        while(!stack.empty()) {
            int i = stack.top().first;
            int val = stack.top().second;

            int size = heights.size();
            rect = max(rect, val * ( size - i));

            stack.pop();
      }

        return rect;
    }
};
