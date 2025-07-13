class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin() , trainers.end());
        sort(players.begin() , players.end());
        int n = trainers.size();
        int m = players.size();
        int i = 0;
        int j = 0;
        int count=0;
        while(i < n){

            if(j < m && players[j] <= trainers[i]){
                j++;
                count++;
            }

            i++;
        }

    return count;
    }
};