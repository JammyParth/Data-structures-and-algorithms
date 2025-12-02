class Solution {
public:

    vector<vector<int>> dp;
    bool solve(vector<int> &nums ,int index , long long sum , int target){
        int n = nums.size();

        if(sum == target){
            return true;
        }

        if(index == n || sum > target){
            return false;
        }

        if(dp[index][sum] != -1){
            return dp[index][sum];
        }

        bool include = solve(nums ,index + 1, sum + nums[index] , target);
        bool exclude = solve(nums , index + 1, sum , target);

        return dp[index][sum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin() , nums.end() , 0);
        dp.resize(n + 1, vector<int> (totalsum + 1, -1));
        if(totalsum % 2 == 1){
            return false;
        }
        long long sum = 0;
        bool res = false;

        int target = totalsum / 2;
        res = solve(nums , 0, sum , target);
        

        return res;

    }
};