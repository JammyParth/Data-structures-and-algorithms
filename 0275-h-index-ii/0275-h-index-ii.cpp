class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        if(n == 1){
            if(nums[0] == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] >= n - mid){
                ans = n - mid;
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};