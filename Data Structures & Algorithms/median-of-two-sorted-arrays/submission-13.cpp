class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if(A.size() > B.size()) {swap(A,B);}

        int size =  nums1.size() + nums2.size();
        int half = (size + 1)/2;

        int left = 0;
        int right = A.size();

        while(left <= right) {
            int i = left + (right - left)/2;
            int j = half - i;


            int midA = i > 0 ? A[i - 1] : INT_MIN;
            int rightA = i < A.size() ? A[i] : INT_MAX;
            int midB = j > 0 ? B[j - 1] : INT_MIN;
            int rightB = j < B.size() ? B[j] : INT_MAX;

            if(midB <= rightA && rightB >= midA) {

                if(size % 2 == 0) {

                    return (max(midA, midB) + min(rightA, rightB) )/ 2.0;


                }
                return max(midA, midB);

            }

            else if(midA > midB) {

                right = i - 1;

            }
            else {
                left = i + 1;
            }


        }

        

        return -1;
    }
};
