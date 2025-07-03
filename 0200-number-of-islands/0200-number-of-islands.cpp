class Solution {
public:


    void dfs(int i , int j , vector<vector<char>>& grid, vector<vector<bool>> &visited) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>> q;
        q.push({i , j});
        visited[i][j] = true;

        vector<int> nrow = {-1 , 0 , 0 , 1};
        vector<int> ncol = {0 , - 1, 1 , 0};

        while(!q.empty()){
            int newrow = q.front().first;
            int newcol = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int row = newrow + nrow[i];
                int col = newcol + ncol[i];

                if(row >= 0 && row < n && col >= 0 && col < m && !visited[row][col]
                && grid[row][col] == '1'){
                    visited[row][col] = true;
                    q.push({row , col});
                }
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