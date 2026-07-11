class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> mp;

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }
        for(int i = 0 ;i < n; i++){
            mp[nums[i]]++;
        }

        int maxi = 0;
        int maxval = 0;
        for(auto val : mp){
            if(val.second > maxi){
                maxi = val.second;
                maxval = val.first;
            }
        }

        return maxval;
    }
};