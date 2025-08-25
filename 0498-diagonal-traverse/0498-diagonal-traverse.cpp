class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0;
        int col = 0;

        vector<int> order;
        bool goingup = true;


        while(row < n && col < m){
            order.push_back(mat[row][col]);


            if(goingup){
                //hitting the right boundary

                if(col == m - 1){
                    row++;
                    goingup = false;
                }


                //hitting the top boundary
                else if(row == 0){
                    col++;
                    goingup = false;
                }


                //travelling normally from row - 1, col + 1
                else{

                    row--;
                    col++;
                }
            }


            else{
                //goingdown

                //hitting the left boundary

                if(row == n - 1){
                    col++;
                    goingup = true;
                }

                //hitting the bottom boundary
                else if(col == 0){
                    row++;
                    goingup = true;
                }

                else{
                    row++;
                    col--;
                }
            }
        }

        return order;
    }
};