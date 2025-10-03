class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //prefix suffix method.
        int n = nums.size();
        vector<int> prefix(n , 1);

        prefix[0] = nums[0];

        for(int i = 1; i< n; i++){
            if(prefix[i - 1] == 0){
                prefix[i] = nums[i];
            }

            else{
            prefix[i] = prefix[i - 1] * nums[i];
            }
        }

        vector<int> suffix(n , 1);
        suffix[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){

            if(suffix[i + 1] == 0){
                suffix[i] = nums[i];
            }

            else{
            suffix[i] = suffix[i + 1] * nums[i];
            }
        }

        int maxproduct = INT_MIN;

        for(int i = 0; i <n; i++){
            maxproduct = max(maxproduct , prefix[i]);
            maxproduct = max(maxproduct, suffix[i]);
        }


    return maxproduct;
    }
};