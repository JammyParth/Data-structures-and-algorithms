class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = nums[0];
        int maxsum = nums[0];


        for(int i =1; i<nums.size();i++){

            sum= max(sum + nums[i] , nums[i]);

            maxsum = max(maxsum, sum);
        }

        return maxsum;


        // int n= nums.size();
        // int maxsum = INT_MIN;

        // for(int i = 0; i < n; i++){
        //     int sum= 0;
        //     for(int j =i; j<n;j++){
        //         sum += nums[j];

        //         maxsum = max(maxsum , sum);
        //     }
        // }
        // return maxsum;
    }
};