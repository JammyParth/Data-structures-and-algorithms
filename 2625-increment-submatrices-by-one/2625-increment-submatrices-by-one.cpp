class Solution {
public:

    void solve(vector<vector<int>>& grid, int row1, int col1, int row2, int col2){
        
        int n = grid.size();

        // if(row1 < n && row2 < n && col1 < n && col2 < n){

        for(int i = row1; i <= row2; i++){
            for(int j = col1; j <= col2; j++){
                grid[i][j] += 1;
            }
        }


        // }
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
                
        vector<vector<int>>grid(n , vector<int>(n , 0));

        int m = queries.size();

        for(int i = 0; i < m; i++){
            solve(grid , queries[i][0] , queries[i][1] , queries[i][2], queries[i][3]);
        }

        return grid;

    }
};