class Solution {
public:
    int n;
    int result;

    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool isPossibleToReach(vector<vector<int>>& grid, int row  ,int col ,int mid, vector<vector<bool>> &visited){

        if(row >= n || row < 0 || col >= n || col < 0 || grid[row][col] > mid || visited[row][col] == true){
            return false;
        }

        visited[row][col] = true;

        if(row == n - 1 && col ==  n- 1){
            return true;
        }

        for(auto &dir : directions){
            int r = row + dir[0];
            int c = col + dir[1];

            if(isPossibleToReach(grid , r , c , mid , visited)){
                return true;
            }
        }

        return false;

    }
    int swimInWater(vector<vector<int>>& grid) {
        //whenever we have to find maximum of minimum / minimum of maximum
        //use BINARY SEARCH ON ANSWERS.
        n = grid.size();
        
        int start = grid[0][0];
        int end = n * n - 1;

        while(start <= end){

            int mid = start + (end - start) / 2;
            vector<vector<bool>> visited(n , vector<bool>(n , false));
            if(isPossibleToReach(grid, 0 , 0 , mid, visited)){
                result = mid;
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        return result;
    }
};