class Solution {
public:

    void solve(vector<vector<int>>& board,vector<vector<int>>&temp, int row, int col){

        int n = board.size();
        int m = board[0].size();

        vector<int> drow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dcol = {-1, 0, 1, -1, 1, -1, 0, 1};

        int population = 0;
        for(int i = 0; i < 8; i++){
            int newrow = row + drow[i];
            int newcol = col + dcol[i];

            if(newrow < n && newcol < m && newrow >= 0 && newcol >= 0){

                if(temp[newrow][newcol] == 1){
                    population++;
                }
            }
        }

        if(population < 2 || population > 3) board[row][col] = 0;
        else if(population == 3) board[row][col] = 1; 

    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> temp = board;
        for(int i= 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                solve(board, temp, i , j);
            }
        }
    }
};