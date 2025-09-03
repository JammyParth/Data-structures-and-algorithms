class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int ,int> mp;
        int n = nums.size();


        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = -1;
        int i = 1;
        while(ans == -1){
            if(!mp.count(i)){
                ans = i;
                break;
            }
            i++;
        }


        return ans;
    }
};