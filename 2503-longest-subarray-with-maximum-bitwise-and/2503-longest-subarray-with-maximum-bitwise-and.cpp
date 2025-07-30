class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxnum = *max_element(nums.begin() , nums.end());
        int maxlen = 0;
        int currlen = 0;


        for(auto val : nums){
            if(val == maxnum){
                currlen++;
                maxlen = max(maxlen, currlen);
            }

            else{
                currlen = 0;
            }
        }

        return maxlen;
    }
};