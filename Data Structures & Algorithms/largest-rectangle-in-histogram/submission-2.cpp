class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stack;
        int rect = 0;
        int start = 0;

        for(int i = 0; i != heights.size(); ++i) {

            start = i;

            while(!stack.empty() && stack.top().second > heights[i]) {

                pair<int,int> current = stack.top();

                rect = max(rect, current.second * (i - current.first)) ;
                start = current.first;
                stack.pop();

            }
            stack.push({start, heights[i]});
        }
        int size = heights.size();
        while(!stack.empty()) {

        int i = stack.top().first;
        int h = stack.top().second;

        
        rect = max(rect, h * (size - i));

        stack.pop();

        }
        return rect;
    }


};
