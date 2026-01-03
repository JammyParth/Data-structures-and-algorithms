class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        if(n == NULL) return 0;
        int count = 1;
        int maxcount = 1;
        for(int i = 1; i<n ; i++){

            if(nums[i - 1] == nums[i]){
                continue;
            }

            if(nums[i - 1] + 1 == nums[i]){
                count++;
                maxcount = max(maxcount, count);
            }

            else{
                count = 1;
            }
        }

    return maxcount;
    }
};