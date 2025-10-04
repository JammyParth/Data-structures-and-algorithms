class Solution {
public:

    vector<int> dp;
    int climbs(int n, int step1, int step2){

        if(n == 0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        step1 = climbs(n - 1, step1 , step2);
        if(n >= 2) step2 = climbs(n - 2, step1, step2);

        return dp[n] = step1 + step2;
    }

    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return climbs(n , 0 , 0);
    }
};