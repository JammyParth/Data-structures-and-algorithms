class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 1);


        // for(int i = 1; i < n; i++){

        //     for(int j= 0; j < i; j++){

        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i] , dp[j] + 1);
        //         }
        //     }
        // }

        // return *max_element(dp.begin() , dp.end());

        vector<int> tail;

        for(auto num : nums){
            auto it = lower_bound(tail.begin() , tail.end() , num);

            if(it == tail.end()){
                tail.push_back(num);
            }

            else{
                *it = num;
            }


        }

        return tail.size();

    }
};