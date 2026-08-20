class Solution {
public:
    bool isPalindrome(string s) {
        string clear;

        for(char c : s) {

            if(isalpha(c) || isdigit(c))

                clear += tolower(c);
        }


        for(int i = 0, j = clear.size()-1; i != clear.size(); ++i, --j) {

            if(clear[i] != clear[j]) return false;

            else if(i == j) return true;
        }

        return true;        
    }
};
