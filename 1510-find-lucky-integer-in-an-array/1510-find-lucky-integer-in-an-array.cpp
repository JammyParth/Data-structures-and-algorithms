class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int ,int> mp;

        for(auto val : arr){
            mp[val]++;
        }

        int maxnum = -1;
        for(auto val : mp){
            if(val.first == val.second){
                maxnum = max(maxnum , val.first);
            }
        }

        return maxnum;
    }
};