class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return -1;

        int mincount = INT_MAX;
        for(int i = 0; i < n; i++){
            int z = -1;
            int k = -1;
            bool flag = false;
            for(int j = i + 1; j < n; j++){
                if(nums[i] == nums[j] && !flag){
                    flag = true;
                    k = j;
                }

                else if(nums[i] == nums[j] && flag){
                    z = j;
                    break;
                }
            }

            if(flag && z != -1 && k != -1){
                mincount = min(mincount , abs(i - z) + abs(z - k) + abs(i - k));
            }
        }

        return (mincount == INT_MAX ? -1 : mincount);
    }
};