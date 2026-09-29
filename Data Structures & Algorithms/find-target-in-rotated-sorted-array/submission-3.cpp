class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int pivot = 0;

        while(left < right) {
            int mid = left + (right - left)/2;

            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }

            else {
                right = mid;
            }

        }

        pivot = left;
        right = nums.size() - 1;
        left = 0;

        if(target >= nums[pivot] && target <= nums[right]) {
            left = pivot;
        }
        else {
            right = pivot;
        }


        while(left <= right) {
            int mid = left + (right - left)/2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }

        }

        return -1;
    }
};
