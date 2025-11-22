class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int ans = (nums[i] % 3);

            if(ans == 2){
                count++;
            }

            else{
                count += ans;
            }
        }

        return count;
    }
};