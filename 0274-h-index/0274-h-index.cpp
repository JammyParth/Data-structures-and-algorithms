class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int n = nums.size();
        int start = 0;
        int end = n - 1;

        int ans = 0;

        while(start <= end){
            int mid = start + (end - start) /2;

            if(n - mid <= nums[mid]){
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