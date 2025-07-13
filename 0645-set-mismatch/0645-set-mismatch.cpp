class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n =nums.size();
        unordered_map<int , int> mp;

        for(auto val : nums){
            mp[val]++;
        }
        int dup;
        for(auto val : mp){
            if(val.second == 2){
                dup = val.first;
            }
        }
        int missing;
        int k = 1;
        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        for(int i =0; i < n; i++){
            if(st.find(k) == st.end()){
                missing = k;
                break;
            }
            k++;
        }

    return {dup , missing};
    }
};