class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> characters;
        int maxS = 0;
        int l = 0;

        for(int r = 0; r != s.size(); ++r) {

            if(characters.find(s[r]) != characters.end()) {
                l = max(characters[s[r]]+1, l);
            }

            characters[s[r]] = r;
            maxS = max(maxS, r - l + 1);
        }

        return maxS;
        
    }
};
