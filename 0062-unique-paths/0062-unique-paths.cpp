class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , int m , int n){

        if(i ==  m - 1 && j == n - 1){
            return 1;
        }

        if(i > m || j > n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int rightshift = solve(i + 1 , j , m , n);
        int downshift = solve(i , j + 1, m, n);


        return dp[i][j] = (rightshift + downshift);
    }
    int uniquePaths(int m, int n) {
        
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
       return solve(0 , 0 , m ,n);
    }
};