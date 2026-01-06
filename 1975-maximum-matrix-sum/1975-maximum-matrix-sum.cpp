class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        long long totalsum = 0;
        int lowest = INT_MAX;
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(matrix[i][j] == 0){
                    flag = true;
                }
                if(matrix[i][j] < 0){
                    count++;
                }
                totalsum += abs(matrix[i][j]);

                lowest = min(lowest , abs(matrix[i][j]));
            }
        }


        if(flag){
            return totalsum;
        }

        if(count % 2 == 0){
            return totalsum;
        }

        return totalsum - lowest - lowest;
    }
};