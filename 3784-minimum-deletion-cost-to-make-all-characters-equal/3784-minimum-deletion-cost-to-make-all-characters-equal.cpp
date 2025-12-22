class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        //all combinations
        //using vector and ascii values.
        vector<long long> ascii(26 , 0);
        int n = s.size();
        // total - alphabet = b + c.
        // a + b + c = total
        // b + c = total - a; 
        // a + c = total - b;
        // a + b = total - c;

        long long totalcost = accumulate(cost.begin() , cost.end() , 0LL);
        for(int i = 0; i < n; i++){
            ascii[s[i] - 'a'] += cost[i];
        }

        long long mincost = LLONG_MAX;

        for(int i = 0; i < 26; i++){
            mincost = min(mincost , totalcost - ascii[i]);
        }


        return mincost;

    }
};