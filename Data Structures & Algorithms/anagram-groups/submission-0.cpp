class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for(string s : strs) {
            string temp = s;
            
            sort(temp.begin(), temp.end());

                hash[temp].push_back(s);
               
            }

        for(auto& s : hash) {

            ans.push_back(s.second);
        }
        return ans;

    
    }
};
