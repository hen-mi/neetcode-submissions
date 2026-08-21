class Solution {
public:
    int trap(vector<int>& height) {
                
        if(height.empty()) return 0;

        int l = 0; int r = height.size()-1;
        int maxL = height[l]; int maxR = height[r];
        int count = 0;
        
        while(l < r) {

        if(maxL < maxR) {
           l++;
           if(height[l] > maxL) maxL = height[l];
           count += maxL - height[l];

        }

        else {
            r--;
            if(height[r] > maxR) maxR = height[r];
            count += maxR - height[r];

        }

        
        }

        return count;

    }
};
