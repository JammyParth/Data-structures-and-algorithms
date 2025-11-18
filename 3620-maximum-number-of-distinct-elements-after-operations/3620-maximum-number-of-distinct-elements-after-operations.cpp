class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
    //     sort(nums.begin() , nums.end());
    //     int n = nums.size();
    //     unordered_map<int , int> mp;


    //     for(int i = n - 1; i >= 0; i--){
    //         int val = nums[i];
    //         int temp2 = val;

    //         if(mp[val] > 0){
                
    //             int temp = -k;
                
    //             while(mp[temp2] > 0 && temp <= k){
    //                 temp2 = val; 
    //                 temp2 += temp;
    //                 temp++;
    //             }
    //         }

    //         mp[temp2]++;
    //     }

    // return mp.size();


        sort(nums.begin(), nums.end());
        long long occupied = LLONG_MIN;  // last assigned value
        int ans = 0;

        for (int x : nums) {
            // Can we place this element at some position in [x - k, x + k]
            // that is > occupied?
            if (occupied < (long long)x + k) {
                long long cur = max(occupied + 1, (long long)x - k);
                occupied = cur;
                ++ans;
            }
        }
        return ans;

    }
};