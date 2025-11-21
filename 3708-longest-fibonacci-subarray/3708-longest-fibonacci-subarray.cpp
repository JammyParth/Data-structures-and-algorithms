class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        
        int count = 2;
        int totalcount = 2;
        for(int i = 2; i < n; i++){
            if(nums[i - 2] + nums[i - 1] == nums[i]){
                count++;
                totalcount = max(count , totalcount);
            }

            else{
                count = 2;
            }
        }


        return totalcount;
    }
};