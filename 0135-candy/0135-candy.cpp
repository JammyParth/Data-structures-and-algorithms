class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n , 1);

        // vector<bool> visited(n , false);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                if(candies[i] < candies[i+1] + 1){
                    candies[i] = candies[i + 1] + 1;
                }
            }
        }

        int totalcandies = 0;
        for(auto val : candies){
            totalcandies += val;

        }


    return totalcandies;
    }
};