class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int top = -1;
        int bottom = -1;
        int left = -1;
        int right = -1;

        bool flag = true;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                //first we have to take the leftmost col, then rightmost col.
                //then we have to take topmost row and bottommost row.
                if(grid[i][j] == 1 && flag){
                    top = i;
                    flag = false;
                }

                if(grid[i][j] == 1){
                    bottom = i;
                }
                //in the same loop i can store bottom too.
            }
        }

        flag = true;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){

                //store the first col and last col.

                if(grid[i][j] == 1 && flag){
                    left = j;
                    flag = false;
                }

                if(grid[i][j] == 1){
                    right = j;
                }
            }
        }

        int l = bottom - top + 1;
        int b = right - left + 1;


        return l * b;
    }
};