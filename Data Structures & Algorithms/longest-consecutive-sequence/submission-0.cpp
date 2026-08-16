class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.size());
        int count = 0;

        for(const auto& n : nums) {

            s.insert(n);

        }

        for(auto& n : s) {

            if(s.find(n-1) == s.end()) {
                int temp = 1;
                int num = n+1;
                while(s.find(num) != s.end() ) {
                    num++;
                    temp++;
                }
            if(temp > count) count = temp;
            }

        }


        return count;
    }
};
