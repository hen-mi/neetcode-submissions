class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freqCount(26,0);
        int ans = 0;
        int l = 0;
        int currMax = s[0] - 'A';
        for(int r = 0; r != s.size(); ++r) {

            freqCount[s[r] - 'A']++;

            if(freqCount[s[r] - 'A'] > freqCount[currMax]) currMax = s[r] - 'A';
       
            if(r - l - freqCount[currMax] >= k) {

                freqCount[s[l] - 'A']--;
                l++;

            }
            else {

                ans =  max(ans, r - l + 1);
            }

        }


        return ans;

    }
};
