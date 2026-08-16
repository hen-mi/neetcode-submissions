class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> one;
        unordered_map<char, int> two;

        for(char c : s) {

            one[c]++;
        }
        for(char c : t) {
            two[c]++;
        }

        return one == two ? true : false;
    }
};
