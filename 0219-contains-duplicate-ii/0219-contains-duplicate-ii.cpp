class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<pair<int , int>> pairs;

        for(int i = 0; i < n; i++){
            pairs.push_back({nums[i]  , i});
        }

        sort(pairs.begin() , pairs.end());

        for(int i = 1; i < n; i++){
            if(pairs[i - 1].first == pairs[i].first){

                if(abs(pairs[i -1].second - pairs[i].second) <= k){
                    return true;
                }
            }
        }

        return false;
    }
};