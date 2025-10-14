class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(2 * k > n) return false;

        vector<int> temp(n , 0);
        for(int i=0; i + k <= n; i++){
            bool flag = true;

            for(int j = i + 1; j < i + k; j++){
                if(nums[j] <= nums[j - 1]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                temp[i] = 1;
            }
        }

        for(int i = 0; i + 2* k <= n; i++){

            if(temp[i] == 1 && 1 == temp[i + k]) return true;
        }

        return false;
    }
};