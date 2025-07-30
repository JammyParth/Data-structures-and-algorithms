class Solution {
public:


    void dfs(int row , int col , vector<vector<char>>& grid, vector<vector<bool>> &visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;

        vector<int> nrows = {-1 , 1 , 0 , 0};
        vector<int> ncols = {0 , 0 , -1, 1};


        for(int i = 0; i < 4; i++){
            int newrow = row + nrows[i];
            int newcol = col + ncols[i];

            if(newrow < n && newrow >= 0 && newcol < m && newcol >=0 
            && !visited[newrow][newcol] && grid[newrow][newcol] == '1'){
                dfs(newrow , newcol , grid, visited);
            }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m , false));
        int count = 0;


        for(int i = 0; i < n; i++){
            for(int j= 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] =='1'){
                    dfs(i , j , grid, visited);
                    count++;
                }
            }
        }
    return count;
    }
};