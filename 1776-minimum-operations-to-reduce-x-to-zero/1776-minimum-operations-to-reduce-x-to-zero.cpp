class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i  = 0;

        int totalsum = accumulate(nums.begin() , nums.end() , 0);
        int target = totalsum - x;

        if(target < 0) return -1;
        int maxlen = -1;
        int currsum = 0;
        for(int j = 0; j < n; j++){
            currsum += nums[j];

            while(currsum > target && i <= j){
                currsum -= nums[i];
                i++;
            }

            if(currsum == target){
                maxlen = max(maxlen , j - i + 1);
            }
        }


        return maxlen == -1 ? -1 : n - maxlen;
    }
};