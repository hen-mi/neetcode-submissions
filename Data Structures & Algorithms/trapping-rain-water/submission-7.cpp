class Solution {
public:
    int trap(vector<int>& height) {

        if (height.empty()) return 0;
        int left = 0;
        int right = height.size() - 1;
        int maxR = height[right];
        int maxL = height[left];

        int count = 0;


        while(left < right) {

        if(maxL < maxR) {
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
