class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start <= end){
            
            int mid = start + (end - start) / 2;

            if(target == nums[mid]){
                return mid;
            }


            if(nums[start] <= nums[mid]){  

                if(nums[start] <= target && target <= nums[mid]){
                    end = mid - 1;
                }

                else{
                    start = mid + 1;
                }
            }

            else{

                if(nums[mid + 1] <= target && target <= nums[end]){
                    start = mid + 1;
                }

                else{
                    end = mid - 1;
                }
            }

        }
    return -1;
    }
};