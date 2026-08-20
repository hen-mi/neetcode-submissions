class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
                
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i != nums.size(); i++) {

            if(nums[i] > 0) break;
            //skip dupe
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1; int r = nums.size()-1;

            while(l < r) {

                int currentsum = nums[i] + nums[l] + nums[r];

                if(currentsum > 0) r--;

                else if(currentsum < 0 ) l++;

                if(currentsum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    //skip dupes for the left part
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                
                 }

            }
        }

        return res;
    }
};
