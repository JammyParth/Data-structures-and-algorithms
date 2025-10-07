class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        map<int , int> mp;
        vector<int> zero;

        vector<int> ans(n , 1);

        for(int i = 0; i < n; i++){

            if(rains[i] == 0){
                zero.push_back(i); //storing the indexes of zero
                continue;
            }

            if(mp.find(rains[i]) != mp.end()){
                //if we find the rain again.

                //we find the first zero day after the rain.
                auto it = lower_bound(zero.begin() , zero.end() , mp[rains[i]]);

                if (it == zero.end()) {
                    return {}; // No day available to dry it
                }

                ans[*it] = rains[i];
                zero.erase(it);
            }

           
            //we store the days inside the map
            mp[rains[i]] = i;
            ans[i] = -1;
            
        }

    return ans;
    }
};