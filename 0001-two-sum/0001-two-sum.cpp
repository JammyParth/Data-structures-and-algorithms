class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;

        int n = nums.size();
        
        for(int i = 0; i< n; i++)
        {
            mp[nums[i]] = i;
        }

        int start = -1;
        int end = -1;

        for(int j = 0; j < n; j++){
            int ops = target - nums[j];

            if(mp.find(ops) != mp.end() && mp[ops] != j){
                start = mp[ops];
                end = j;
                break;
            }
        }


        return {start , end};
    }
};