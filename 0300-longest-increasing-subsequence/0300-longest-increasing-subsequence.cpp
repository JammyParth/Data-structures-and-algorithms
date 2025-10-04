class Solution {
public:


    vector<vector<int>> dp;
    int solve(vector<int>& nums, int prev, int index){

        int  n = nums.size();
        if(index == n){
            return 0;
        }

        if(dp[index][prev + 1] != -1){
            return dp[index][prev + 1];
        }

        //excluding the current element.
        int exclude = solve(nums, prev, index + 1);


        int include = 0;
        if(prev == -1  || nums[index] > nums[prev]){
            include = 1 + solve(nums, index , index + 1);
        
        }

        return dp[index][prev + 1] = max(include , exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(2501 , vector<int>(2501, -1));
        return solve(nums, -1, 0);
    }
};