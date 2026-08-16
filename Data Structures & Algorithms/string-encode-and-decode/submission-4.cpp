class Solution {
public:

    string encode(vector<string>& strs) {

        string encoded;

        for(const auto& s : strs) {

            encoded += to_string(s.size()) + ":" + s;

        }

        cout << encoded << " ";
        return encoded;



    }

    vector<string> decode(string s) {

        vector<string> ans;
        int i =0;

        while(i != s.size()) {
            int j = i;
            while(s[j] != ':') {
                j++;
            }

            int size = stoi(s.substr(i, j - i));
            j++;
            ans.push_back(s.substr(j, size));

            i = j + size;
        }

        return ans;
    }
};
