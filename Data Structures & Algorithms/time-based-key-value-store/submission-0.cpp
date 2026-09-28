class TimeMap {
private:
unordered_map<string, vector<pair<string, int>>> values;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        values[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        
        auto& v = values[key];
        int left = 0;
        int right = v.size() - 1;
        string ans = "";
        while(left <= right) {
            
            int mid = left + (right-left)/2;

            if(v[mid].second <= timestamp ) {
                ans = v[mid].first;
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }

        }


        return ans;
    }
};
