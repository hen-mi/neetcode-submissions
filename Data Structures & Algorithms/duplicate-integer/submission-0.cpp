class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> dup;

        for(int n : nums) {

            dup[n]++;

            if(dup[n] > 1) return true;
        }

        return false;
    }
};