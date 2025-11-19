class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        
        unordered_map<int , int> mp;

        for(auto val : nums){
            mp[val]++;
        }

        while(mp[original] > 0){
            original *= 2;
        }

        return original;
    }
};