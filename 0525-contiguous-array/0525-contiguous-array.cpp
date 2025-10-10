class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;

        int sum = 0;
        int maxsize = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                sum -= 1;
            }

            else{
                sum += 1;
            }

            if(sum == 0 && i > 0){
                maxsize = max(maxsize , i + 1);
            }

            if(mp.count(sum)){
                maxsize = max(maxsize , i - mp[sum]);
            }

            else{
                mp[sum] = i;
            }

        }

        return maxsize;
    }
};