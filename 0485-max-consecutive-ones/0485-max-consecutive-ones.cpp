class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int count = 0;
        int n = nums.size();
        int maxcount = 0;
        while(i < n){
            if(nums[i] == 1){
                count++;

            }
            else{
                maxcount = max(maxcount , count);
                count = 0;
            }
            i++;
        }
        
        return max(maxcount, count);
    }
};