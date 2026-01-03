class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto &val : strs){
            string sorted_val = val;
            sort(sorted_val.begin() , sorted_val.end());
            mp[sorted_val].push_back(val);
        }
        
        vector<vector<string>> ans;

        for(auto &val : mp){
            ans.push_back(val.second);
        }


    return ans;
    }
};