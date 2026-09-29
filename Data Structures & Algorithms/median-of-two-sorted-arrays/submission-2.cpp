class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2; //size the left side must have on merge, +1 for rounding on odd sizes

        if(B.size() < A.size()) {
            swap(A, B);
        }
        int left = 0;
        int right = A.size();

        while(left <= right) {
            int i = (left + right) / 2;
            int j = half - i; //left most element of the right side, may change

            int Aleft = i > 0 ? A[i-1] : INT_MIN; //tends to negative infinity if no number, avoid edge cases
            int Aright = i < A.size() ? A[i] : INT_MAX; //same ideia, but for the other side
            int Bleft = j > 0 ? B[j-1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright) //correct side of left, is merged
            {
                if(total % 2 == 0) {
                    return (double) (max(Aleft, Bleft) + min(Aright, Bright) )/ 2.0;
                }
                return (double) max(Aleft, Bleft);
            }

            else if(Aleft > Bright) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }




        }

        return -1;
    }
};
