class Solution {
public:

    bool isValid(vector<int>& nums, int k){
        int n= nums.size();

        int i = 1;
        int temp = k;
        int count = 0;
        while(k < n - 1){
            if(nums[i] > nums[i - 1] && nums[k + 1] > nums[k]){
                count++;
            }

            else{
                count = 0;
            }


            if(count == temp - 1){
                return true;
            }
            i++;
            k++;

        }

        return false;

    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int start = 2;
        int end = n / 2;
        int result = 1;

        while(start <= end){
            int mid = start + (end - start) / 2;


            if(isValid(nums , mid)){
                result = mid;
                start = mid + 1;
            }

            else{
                end = mid - 1;
            }
        }

    return result; 
    }
};