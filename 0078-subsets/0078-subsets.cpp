class Solution {
public:

    void solve(vector<int> &nums , vector<vector<int>> &ans , int index, vector<int> &levels){
        // base condition
        int n = nums.size();
        
        if(index == n){
            ans.push_back(levels);
            return;
        }

        levels.push_back(nums[index]);
        solve(nums, ans, index + 1, levels);
        levels.pop_back();
        solve(nums, ans, index + 1, levels);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        vector<int> levels;
        // int n = nums.size();
        solve(nums, ans, index, levels);

        return ans;
    }
};