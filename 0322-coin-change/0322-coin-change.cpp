class Solution {
public:

    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount, int index){
        

        if(amount == 0){
            return 0;
        }

        //base condition
        if(amount < 0 || index < 0){
            return INT_MAX;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        //include
        int include = solve(coins , amount - coins[index], index);
        if (include != INT_MAX) include += 1; // count this coin
        //exclude
        int exclude = solve(coins , amount , index - 1);

        return dp[index][amount]= min(include , exclude);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int index = n - 1;

        sort(coins.begin() , coins.end());
        dp.resize(n + 1, vector<int>(amount + 1 , -1));
        int res = solve(coins , amount , index);

        if(res == INT_MAX){
            return -1;
        }

        return res;
    }
};