class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        int count = 0;
        int left = 0;
        int right = 0;

        int m1 = 0;
        int m2 = 0;

        while(count < (size1 + size2)/2 + 1) {
            
            m2 = m1;

            if(left < size1 && right < size2) {
    
                if(nums1[left] > nums2[right]) {
                    m1 = nums2[right];
                    right++;
                } else {
                    m1 = nums1[left];
                    left++;
                }


            }
            else if(left < size1) {
                m1 = nums1[left];
                left++;
            }
            else {
                m1 = nums2[right];
                right++;
            }

            count++;
        }



        if((size1 + size2) % 2 == 0) {
            return (double) (m1 + m2) /2.0;
        }
        

        return (double) m1;
    }
};
