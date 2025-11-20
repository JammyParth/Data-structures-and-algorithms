class Solution {
public:

    vector<vector<int>> dp;
    int function(int x, int y , int row , int col, vector<vector<int>>& obstacleGrid){

        if(obstacleGrid[row-1][col-1] == 1){
            return 0;
        }

        if(x == row -1 && y == col - 1){
            return 1;
        }

        if(x >= row || y >= col){
            return 0;
        }

        if(obstacleGrid[x][y] == 1){
            return 0;
        }

        if( dp[x][y] != -1){
            return  dp[x][y];
        }
        
        int leftshift = function(x + 1, y , row  , col , obstacleGrid);
        int downshift = function(x  , y + 1 , row , col , obstacleGrid);
        

        return dp[x][y] = leftshift + downshift;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        dp = vector<vector<int>>(row + 1 ,vector<int>(col + 1, -1));
        int res = function(0 , 0, row , col, obstacleGrid);
        return res;
    }
};