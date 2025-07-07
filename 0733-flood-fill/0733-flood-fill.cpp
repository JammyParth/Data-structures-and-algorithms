class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n ,vector<int>(m, 0));

        int target = image[sr][sc];
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        queue<pair<int , int>> q;
        q.push({sr, sc});


        vector<int> newrow = {-1, 0 , 1, 0};
        vector<int> newcol = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for(int i = 0; i < 4; i++){
                int nrow = newrow[i] + row;
                int ncol = newcol[i] + col;

                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0
                && image[nrow][ncol] == target && vis[nrow][ncol] == 0){
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow , ncol});
                }
            }
        }

    return image;

    }
};