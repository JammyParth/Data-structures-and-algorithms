class Solution {
public:


    void solve(int i , vector<vector<int>> &ans){
        
        if(i == 0){
            return;
        }
         
        solve(i - 1, ans);

        for(int j = 1; j< i; j++){
            ans[i][j] = ans[i -1][j - 1] + ans[i - 1][j];
        }


    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>(1 , 1));

        for(int i = 1; i < numRows; i++){
            ans[i].resize(i + 1, 1);
        }

        solve(numRows - 1 , ans);
        return ans;


    }
};