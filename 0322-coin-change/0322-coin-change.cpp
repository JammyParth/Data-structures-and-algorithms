class Solution {
public:

    vector<vector<int>>dp;
    int solve(vector<int>& coins, int target , int index){
        int n = coins.size();

        if(target == 0){
            return 0;
        }

        if(index < 0 || target < 0) return INT_MAX;


        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int include = solve(coins , target - coins[index] , index);
        
        if(include != INT_MAX) include += 1;

        int exclude = solve(coins, target, index - 1);


        return dp[index][target] = min(include , exclude);
    }
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();

        dp = vector<vector<int>>(n + 1, vector<int>(sum + 1 , -1));
        sort(coins.begin() , coins.end());

       int ans = solve(coins, sum ,n -1);

       return (ans == INT_MAX) ? -1 : ans;
        // int target = sum;
        // int count= 0;
        // int j = n - 1;
        // while(j >= 0 && target != 0){
            
        //     if(coins[j] <= target){
        //         target -= coins[j];
        //         count++;
        //     }
        //     else if(coins[j] > target){
        //         j--;
        //     }
        // }
        
        
        // if(target == 0) return count;
        
        // return -1;

    }
};