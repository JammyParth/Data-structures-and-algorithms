class Solution {
public:
    int n;
    int m;
    int result;
    
    vector<vector<int>> directions = {{-1, 0} , {1 , 0} , {0 , -1} , {0 , 1}};

    bool isPossible(vector<vector<int>>& heights , int row , int col ,int prev ,  int mid , vector<vector<bool>> &visited){

        if(row >= n || row < 0 || col >= m || col < 0 || abs(heights[row][col] - prev) > mid || visited[row][col] == true){
            return false;
        }

        visited[row][col] = true;

        if(row == n - 1 && col == m - 1){
            return true;
        }

        for(auto &dir : directions){
            int r = row + dir[0];
            int c = col + dir[1];


            if(isPossible(heights , r , c , heights[row][col] , mid ,  visited)){
                return true;
            }
        }

        return false;

    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        int start = 0;
        int end = pow(10 , 6) - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            vector<vector<bool>> visited(n , vector<bool>(m , false));
            if(isPossible(heights, 0 , 0 , heights[0][0], mid , visited)){
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