class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int n = nums.size();
        if(n < 3) return nums[0];

        int i = 1;
        int ans = -1;
        while(i < n){
            if(nums[i - 1] == nums[i] && nums[i] == nums[i + 1]){
                i += 3;
            }

            else{
                ans = nums[i - 1];
                break;
            }
        }

        if(ans == -1) return nums[n - 1];
        return ans;
    }
};