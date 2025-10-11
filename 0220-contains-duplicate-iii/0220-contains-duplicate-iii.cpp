class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(indexDiff < 1){
            return false;
        }

        int n = nums.size();
        set<int> st;

        for(int i = 0; i < n; i++){

            auto it = st.lower_bound(nums[i] - valueDiff);

            if(it != st.end() && *it - nums[i] <= valueDiff){
                return true;
            }

            st.insert(nums[i]);

            if(st.size() > indexDiff){
                st.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};