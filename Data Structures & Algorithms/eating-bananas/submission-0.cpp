class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1;
        int ans = 1;
        for(int p : piles) {
            if(p > right) right = p;
        }

        while(left <= right) {
            int k = left + (right-left)/2;
            long long time = 0;
            for(int p : piles) {
                time += ceil(static_cast<double>(p) / k);
            }
            
            if(time <= h) {
                ans = k;
                //tries to find smaller
                right = k - 1;
            }
            else {
                //still has hours left, go up
                left = k + 1;
            }
        }

        return ans;
    }
};
