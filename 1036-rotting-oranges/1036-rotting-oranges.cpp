class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int , int> ,  int>> q;
        vector<vector<int>> vis(n , vector<int> (m , 0));

        int time = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i , j} , time});
                }
            }
        }

        vector<int> newrow = {-1 , 0 , 1 , 0};
        vector<int> newcol = {0 , 1 , 0 , -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currtime = q.front().second;
            
            q.pop();
            time = max(time ,currtime);

            for(int i = 0; i < 4; i++){
                int nrow = newrow[i] + row;
                int ncol = newcol[i] + col;

                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow , ncol} , currtime + 1});
                }
            }
        }
        

        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    return -1;
                }
            }
        } 

    return time;
    }
};