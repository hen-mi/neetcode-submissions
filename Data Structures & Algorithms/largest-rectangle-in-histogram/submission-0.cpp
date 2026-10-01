class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stack;
        int rect = 0;

        for(int i = 0; i < heights.size(); ++i) {

            int start = i;

            while(!stack.empty() && stack.top().second > heights[i]) {
                pair<int, int> temp = stack.top();
                int index = temp.first;
                int h = temp.second;

                rect = max(rect, h * (i - index));
                start = index;
                stack.pop();
         }



            stack.push({start, heights[i]});

        }


        while(!stack.empty()) {
            int i = stack.top().first;
            int h = stack.top().second;
            int size = heights.size();
            rect = max(rect, h * ( size - i));

            stack.pop();

        }

        return rect;
    }
};
