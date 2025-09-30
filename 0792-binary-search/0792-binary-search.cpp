class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        long long start = 0;
        long long end = n - 1;

        while(start <= end){

            long long mid = start + (end - start) / 2;

            if(target == nums[mid]){
                return mid;
            }

            else if(target < nums[mid]){
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }
    return -1;
    }
};