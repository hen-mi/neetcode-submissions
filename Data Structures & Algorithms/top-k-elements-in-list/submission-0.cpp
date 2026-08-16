class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> amount;
        vector<int> ans (k,0);
        for(int& n : nums) {

            amount[n]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : amount) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());
      

        for(int i = 0; i != k; i++) {

            ans[i] = arr[i].second;


        }


        return ans;


    }
};
