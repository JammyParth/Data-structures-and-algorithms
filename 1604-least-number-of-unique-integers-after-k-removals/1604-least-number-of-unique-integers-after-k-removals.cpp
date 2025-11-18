class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int , int>> ans;
        unordered_map<int , int> mp;
        

        for(auto val : arr){
            mp[val]++;
        }

        for(auto val : mp){
            ans.push_back({val.second , val.first});
        }

        sort(ans.begin() , ans.end());

        int count = 0;
        for(auto val : ans){
            if(val.first <= k){
                count++;
            }
            k -= val.first;
        }

        return ans.size() - count;
    }
};