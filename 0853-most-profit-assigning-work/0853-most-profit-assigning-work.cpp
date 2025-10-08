class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        vector<pair<int , int>> pairs;
        int n = profit.size();
        for(int i = 0; i < n; i++){
            pairs.push_back({difficulty[i] , profit[i]});
        }

        sort(pairs.begin() , pairs.end());



        for (int i = 1; i < n; i++) {
            pairs[i].second = max(pairs[i].second, pairs[i - 1].second);
        }

        int totalprofit = 0;
        for(auto worker : workers){

            auto it = upper_bound(pairs.begin() , pairs.end() ,make_pair(worker , INT_MAX));

            if(it != pairs.begin()){
                --it;
                totalprofit += it -> second;
            }

        }

        return totalprofit;
    }
};