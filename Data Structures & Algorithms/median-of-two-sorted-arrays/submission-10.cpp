class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>& A = nums1;
        vector<int>& B = nums2; 
        int size =  nums1.size() + nums2.size();

        if(A.size() > B.size()) {
            swap(A,B);
        }

        int half = (size + 1) / 2;
        int left = 0;
        int right = A.size();


        while(left <= right) {
            int i = (left + right) / 2;
            int j = half - i;

            int leftA = i > 0 ? A[i - 1] : INT_MIN;
            int rightA = i < A.size() ? A[i] : INT_MAX;
            int leftB = j > 0 ? B[j - 1] : INT_MIN;
            int rightB = j < B.size() ? B[j] : INT_MAX;


            if(leftB <= rightA && rightB >= leftA ) {
                
                if(size % 2 == 0) {

                    return (min(rightA, rightB) + max(leftA, leftB)) / 2.0;
                }

                return max(leftB, leftA);
            }

            else if(leftA > leftB) {
                right = i - 1;
            }

            else {
                left = i + 1;
            }





        }

        return -1;
    }
};
