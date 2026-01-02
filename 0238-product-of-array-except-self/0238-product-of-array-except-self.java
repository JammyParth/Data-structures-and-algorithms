class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        int[] ans = new int[n];

        prefix[0]= 1;

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        suffix[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // int prod = 1;
        // for(int i = 1; i < n; i++){
        //     prod *= nums[i];
        // }

        // if(nums[0] < 2) ans[0] = suffix[0];
        // else ans[0] = prod;
        // ans[n - 1] = prefix[n - 2];


        for(int i=0; i < n; i++){
            ans[i] = suffix[i] * prefix[i];
        }

        return ans;
    }
}