class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n  = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n , vector<int> (m , 0));
        for(int i = n - 1; i >= 0; i--){

            for(int j = m - 1; j >= 0; j--){
                if(i == n - 1 && j == m - 1){
                    dp[i][j] = dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1;
                }


                else{

                int right = (j + 1 >= m) ? 1e9 : dp[i][j + 1];
                int down = (i + 1 >= n) ? 1e9 : dp[i + 1][j];

                int result = min(down , right) - dungeon[i][j];

                dp[i][j] = result > 0 ? result : 1;
                }
            }
        }

        return dp[0][0];
    }
};