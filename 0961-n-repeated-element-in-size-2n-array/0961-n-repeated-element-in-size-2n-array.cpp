class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int , int> mp;

        int n = nums.size() / 2;
        for(auto val : nums){
            mp[val]++;
        }

        for(auto val : mp){
            if(val.second == n){
                return val.first;
            }
        }

        return -1;
    }
};