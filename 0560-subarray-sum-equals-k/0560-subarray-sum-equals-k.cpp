class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
       
    //    if(nums.size() == 0){
    //     return 0;
    //    }
    //     unordered_map<int, int> mp;
    //     mp[0]++;
    //     int sum = 0;
    //     int count = 0;
    //    for(auto val : nums){
    //     sum += val;

    //     if(mp.find(sum - k) != mp.end()){
    //         count += mp[sum - k];
    //     }

    //     mp[sum]++;
    //    }

    // return count;
    // }

    if(nums.size() == 0){
        return 0;
    }

    unordered_map<int, int> mp;
    int n = nums.size();
    vector<int> prefixsum(n , 0);

    prefixsum[0] = nums[0];
    mp[0] = 1;
    int count = 0;

    for(int i = 0; i < n; i++){

        if(i > 0) prefixsum[i] = prefixsum[i - 1] + nums[i];

        if(mp.find(prefixsum[i] - k) != mp.end()){
            count += mp[prefixsum[i] - k];
        }

        mp[prefixsum[i]]++;

    }


    return count;
    
    }

    
};