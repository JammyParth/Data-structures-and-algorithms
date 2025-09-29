class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int val = 0;
        int maxval = 0;

        for(int i = 0; i < n; i++){
            val += gain[i];
            maxval = max(maxval , val);
        }


        return maxval;

    }
};