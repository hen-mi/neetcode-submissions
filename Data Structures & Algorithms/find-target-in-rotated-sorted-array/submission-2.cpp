class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;


        while(left <= right) {
            
            int mid = left + (right-left)/2;

            if(nums[mid] == target) return mid;

            //left is sorted (mid might be the end of the sort)
            if(nums[mid] > nums[right]) 
            {
                //target is in this subarray
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }

            }

            //right is sorted
            else 
            {
                if(target <= nums[right] && nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }

            }


        }


        return -1;
    }
};
