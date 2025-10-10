class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //a very imp concept: if (number + other number) % k = same modulo as with number % k , then the other number is divisible by k.

        if(n < 2){
            return false;
        }

        unordered_map<int , int> mp;
        int zerocount = 0;
        mp[0] = -1; 

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zerocount++;

                if(zerocount >= 2){
                    return true;
                }
            }

            else{
                zerocount = 0;
            }

            sum += nums[i];
            int mod = sum % k;

            if(mod == 0 && i > 0){
                return true;
            }

            if(mp.find(mod) != mp.end()){
                if(i - mp[mod] >= 2){
                    return true;
                }
            }

            else{
                mp[mod] = i;
            }

        }

        return false;
    }
};