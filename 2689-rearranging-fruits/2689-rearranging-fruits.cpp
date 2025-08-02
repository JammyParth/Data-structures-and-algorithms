class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int ,int> mp;

        int n = basket1.size();
        int m = basket2.size();

        for(int i = 0; i < n; i++){
            mp[basket1[i]]++;
        }

        for(int i = 0; i < m; i++){
            mp[basket2[i]]--;
        }

        vector<int> swap;

        int minfruit = INT_MAX;
        for(auto val : mp){
            if(val.second % 2 == 1) return -1;
            //we have to take out the freq / 2 elements out in an array.
            //if neg freq then take abs freq / 2 in other array.

            minfruit = min(minfruit , val.first);
                int takeout = abs(val.second) / 2;
                while(takeout != 0){
                    swap.push_back(val.first);
                    takeout--;
                }
        }

        int z = swap.size();
        int till = z / 2;
        sort(swap.begin() , swap.end());
        long long sum = 0;
        for(int i = 0; i < till; i++){
            sum += min(swap[i] ,2* minfruit);
        }


        return sum;
    }
};