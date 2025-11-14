class Solution {
public:

    void solve(vector<vector<int>> &grid , int row1 , int col1 , int row2, int col2){

        int n = grid.size();
        for(int i = row1; i <= row2; i++){

            grid[i][col1] += 1;

            if(col2 + 1 < n){
                grid[i][col2 + 1] -= 1;
            }
        }
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& nums) {
        vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

        int m = nums.size();

        for(int i = 0; i < m; i++){
            solve(grid, nums[i][0] ,  nums[i][1] ,  nums[i][2]  ,  nums[i][3]);
        } 

        
        for(int i = 0; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                grid[i][j] += grid[i][j - 1];
            }
        }

        vector<vector<int>> ans(n , vector<int> (n , 0));

        for(int i = 0 ; i <n; i++){
            for(int j = 0; j  <n; j++)
            {
                ans[i][j] = grid[i][j];
            }
        }


        return ans;
    }
};