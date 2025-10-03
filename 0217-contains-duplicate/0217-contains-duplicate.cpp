class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int, int> mp;

        // for(auto val : nums){
        //     mp[val]++;
        // }

        // for(auto val : mp){
        //     if(val.second > 1){
        //         return true;
        //     }
        // }

        // return false;

        set<int> st(nums.begin() , nums.end());
        return st.size() != nums.size();
    }
};