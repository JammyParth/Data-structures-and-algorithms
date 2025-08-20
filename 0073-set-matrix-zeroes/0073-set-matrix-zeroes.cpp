class Solution {
public:

    void solve(vector<vector<int>>& matrix, int row , int col){
        int n= matrix.size();
        int m = matrix[0].size();


        //setting row before 0
        for(int i = row; i >= 0; i--){
            matrix[i][col] = 0;
        }
        
        for(int i = row; i < n; i++){
            matrix[i][col] = 0;
        }

        //setting col 0

        for(int i = col; i >= 0; i--){
            matrix[row][i] = 0;
        }

        for(int i = col; i < m; i++){
            matrix[row][i] = 0;
        }

    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n= matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> temp = matrix;
        for(int i = 0; i <n; i++){
            for(int j= 0; j < m; j++){
                if(temp[i][j] == 0){
                    solve(matrix, i , j);
                }
            }
        }
    }
};