class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int i = 0;
        if(n == 1) return 0;
        int j = 1;
        int maxcount = 0;
        int count = 0;
        while(j < n){
            //condition
            if(nums[j] - nums[i] == 1){
                count = j - i + 1;
                maxcount = max(maxcount , count);
                j++;
            }
            else if(nums[j] - nums[i] < 1){
                j++;
            }
            else{
                i++;
            }
        }
        return maxcount;
    }
};