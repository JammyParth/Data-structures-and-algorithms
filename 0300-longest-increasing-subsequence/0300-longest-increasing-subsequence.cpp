class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for(auto val : nums){

            auto it = lower_bound(ans.begin() , ans.end() , val);

            if(it == ans.end()){
                ans.push_back(val);
            }

            else{
                *it = val;
            }
        }

        return ans.size();
    }
};