class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int k = s1.size();
        vector<int> target(26, 0);

        vector<int> currSum(26,0);
        for(char& c : s1) {

            target[c - 'a']++;
        }

        for(int r = 0; r != s2.size(); ++r) {

            while(r - l >= k) {

                currSum[s2[l] - 'a']--;
                l++;
            }
         

                currSum[s2[r] - 'a']++;

                if(target == currSum) return true;
        
            

        }


        return false;
    }
};
