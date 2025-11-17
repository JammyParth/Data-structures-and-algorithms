class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //[0 , 1 , 2 , 3 , 4 , 5]
        vector<int> ans;

        int i = 0;
        int j = n;
        while(j < 2*n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }

        return ans;
    }
};