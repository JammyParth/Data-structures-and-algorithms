class Solution {
public:

    void solve(vector<int> &nums, int currOR , int &maxOR, int index ,int &count){

        //base case
        int n = nums.size();
        if(index == n){
            if(currOR == maxOR){
                count++;
            }
            return;
        }

        solve(nums , currOR | nums[index] , maxOR, index + 1, count);

        solve(nums , currOR , maxOR , index + 1, count);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for(auto val : nums){
            maxOR |= val;
        }

        int count = 0;

        solve(nums, 0 , maxOR , 0 , count);

        return count;
    }   
};