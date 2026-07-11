class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> mp;

        for(int i = 0; i < n; i++){
            mp.insert({nums[i] , i});
        }

        for(int i = 0; i < n; i++){
            int val = target - nums[i];

            if(mp.find(val) != 0 && mp[val] != i){
                return {i , mp[val]};
            }
        }


        return {-1 , -1};
    }
};