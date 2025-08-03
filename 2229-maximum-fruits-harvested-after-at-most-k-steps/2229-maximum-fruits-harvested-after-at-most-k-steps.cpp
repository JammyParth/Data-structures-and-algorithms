class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int n = fruits.size();

        vector<int> positions(n); //sorted already
        vector<int> prefixsum(n); //fruits prefix sum

        for(int i = 0; i < n; i++){
            positions[i] = fruits[i][0];
            prefixsum[i] = fruits[i][1] + (i > 0 ? prefixsum[i - 1] : 0);
        }


        int maxfruits = 0;

        for(int d = 0; d <= k/2; d++){
            

            //case 1 -> d steps towards left then k - 2d towards right.
            int remain = k - 2*d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(begin(positions) , end(positions) , i) - begin(positions);
            int right = upper_bound(begin(positions) , end(positions) , j) - begin(positions) - 1;

            if(left <= right){
                int total = prefixsum[right] - (left > 0 ? prefixsum[left - 1] : 0);
                maxfruits = max(maxfruits , total);
            }


            //case 2: moved d steps towards right, then k - 2d towards left;

            remain = k - 2*d;
            j = startPos + d;
            i = startPos - remain;

            left = lower_bound(begin(positions) , end(positions) , i) - begin(positions);
            right = upper_bound(begin(positions) , end(positions) , j) - begin(positions) - 1;

            if(left <= right){
                int total = prefixsum[right] - (left > 0 ? prefixsum[left - 1] : 0);
                maxfruits = max(maxfruits , total);
            }

        
        }

    return maxfruits;
    }
};