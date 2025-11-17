class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(auto val : nums){
            ans.push_back(val);
        }
        for(auto val : nums){
            ans.push_back(val);
        }


        return ans;
    }
};