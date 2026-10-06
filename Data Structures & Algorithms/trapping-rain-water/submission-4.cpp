class Solution {
public:
    int trap(vector<int>& height) {

        if (height.empty()) return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxL = height[left];
        int maxR = height[right];
        int count = 0;
        while(left < right) {

            if(height[left] < height[right]) {

                left++;
                maxL = max(maxL, height[left]);

                count += maxL - height[left];
            }

            else {
                right--;
                maxR = max(maxR, height[right]);

                count += maxR - height[right];
            }



        }

        return count;
    }
};
