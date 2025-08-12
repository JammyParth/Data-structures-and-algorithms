class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(vector<int> &powers, int index, int target){
        
        int n = powers.size();
        if(target == 0) return 1;
        if(index >= n || target < 0) return 0;

        if(dp[index][target] != -1){
            return dp[index][target];
        }
        //include and exclude
        int include = solve(powers, index + 1, target - powers[index]);
        int exclude = solve(powers, index + 1, target);


        return dp[index][target] = (include + exclude) % MOD;
    }
    int numberOfWays(int n, int x) {
        vector<int> powers;

        
        // Generate powers <= n
        for (int i = 1; ; i++) {
            int p = pow(i, x);
            if (p > n) break;  // no need to go further
            powers.push_back(p);
        }

        dp.assign(powers.size() + 1, vector<int>(n + 1, -1));

        return solve(powers, 0 , n);
    }
};