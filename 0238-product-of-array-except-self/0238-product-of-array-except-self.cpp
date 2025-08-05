class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int totalproduct = 1;
        int zerocount = 0;
        bool iszero = false;
        for(int i= 0; i < n; i++){
            if(nums[i] != 0){ 
                totalproduct *= nums[i];
            }
            else{
                zerocount++;
                iszero = true;
            }
        }

        if(zerocount > 1){

            for(int i = 0; i < n; i++){
                nums[i] = 0;
            }

            return nums;
        }

        for(int i = 0; i < n; i++){
            if(iszero){
                if(nums[i] != 0){
                    nums[i] = 0;
                }

                else{
                    nums[i] = totalproduct;
                }
            }

            else{
                nums[i] = totalproduct / nums[i];
            }
        }


    return nums;
    }
};