class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> characters;
        int maxS = 0;
        int l = 0;

        for(int r = 0; r != s.size(); ++r) {

            while(characters.contains(s[r])) {
                characters.erase(s[l]);
                l++;
            }
            characters.insert(s[r]);
            maxS = max(maxS, r - l + 1);
        }

        return maxS;
    }
};
