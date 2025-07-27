class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }

        int n = ans.size();
        int hills = 0;
        int valleys= 0;
        for(int i =1; i < n - 1; i++){
            if(ans[i] > ans[i - 1] && ans[i] > ans[i + 1]){
                hills++;
            }

            else if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]){
                valleys++;
            }
        }

    return (hills + valleys);
    }
};