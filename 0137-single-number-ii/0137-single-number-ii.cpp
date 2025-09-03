class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> mp;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = -1;
        for(auto val : mp){
            if(val.second < 3){
                ans = val.first;
            }
        }


        return ans;
    }
};