class Solution {
public:
    string minWindow(string s, string t) {

    if (s.empty() || t.empty() || s.length() < t.length()) return "";


    int minL = 0; 
    int minLen = INT_MAX;

    int l = 0;
    unordered_map<char, int> targetT;
    int currCount = 0;
    unordered_map<char, int> window;
    for(char& c : t) {
        targetT[c]++;
    }

    for(int r = 0; r != s.size(); ++r) {

        if(targetT.count(s[r])) {
            window[s[r]]++;

            if(window[s[r]] == targetT[s[r]]) currCount++;
        }


        while(currCount == targetT.size()) {
            
            if(r - l +1 < minLen) {
                minL = l;
                minLen = r-l + 1;
            }
            
            if(targetT.count(s[l])) {
                window[s[l]]--;

                if(window[s[l]] < targetT[s[l]]) currCount--;
            }

            l++;
        }


    }

    return minLen == INT_MAX ? "" : s.substr(minL, minLen);
            

    }
};
