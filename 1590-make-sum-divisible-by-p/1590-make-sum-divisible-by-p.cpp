class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalsum = 0;

        if(n == 1){
            if(nums[0] % p != 0){
                return -1;
            }
        }

        for(int i = 0; i < n; i++){
            totalsum += nums[i];
        }

        int target = totalsum % p;

        if(target == 0){
            return 0;
        }

        // vector<int> prefixsum(n);
        // prefixsum[0] = nums[0];

        // for(int i =1; i <n ;i++){
        //     prefixsum[i] = prefixsum[i - 1] + nums[i];
        // }

        unordered_map<int , int> mp;

        mp[0] = -1;  // prefix before start

        long long prefix = 0;
        int minsize = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int cur = prefix % p;
            int need = (cur - target + p) % p;

            if (mp.count(need)) {
                minsize = min(minsize, i - mp[need]);
            }

            // store latest index for this remainder
            mp[cur] = i;
        }

        if (minsize == n || minsize == INT_MAX) return -1;
        return minsize;
    }
};