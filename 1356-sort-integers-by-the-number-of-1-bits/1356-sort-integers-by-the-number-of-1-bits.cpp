class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int , int>> res;

        for(auto val : arr){
            int bits = __builtin_popcount(val);
            res.push_back({bits , val});
        }

        sort(res.begin() , res.end());

        arr.clear();

        for(auto val : res){
            arr.push_back(val.second);
        }

        return arr;
    }
};