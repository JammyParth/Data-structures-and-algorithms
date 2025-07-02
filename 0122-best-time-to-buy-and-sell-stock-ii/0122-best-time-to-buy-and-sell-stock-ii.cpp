class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int totalprofit = 0;
        // int minprice = nums[0];

        // int i = 1;
        for(int i= 1; i < n;i++){
            int minprice = nums[i - 1];

            if(nums[i] > minprice){
            totalprofit += nums[i] - minprice;
            }
        }

        return totalprofit;
    }
};