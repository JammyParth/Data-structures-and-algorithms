class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        // if(n == 0) return 0;

        int minprice = nums[0];
        int maxprofit = 0;
        int profit = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < minprice){
                minprice = nums[i];
            }
            else{
                profit = nums[i] - minprice;
                maxprofit = max(profit , maxprofit);
            }
        }

        return maxprofit;
    }
};