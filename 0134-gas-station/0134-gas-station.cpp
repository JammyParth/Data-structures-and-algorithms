class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n  = gas.size();
        int totalgas = 0;
        int currgas = 0;

        int startindex = 0;
        for(int i = 0; i < n; i++){
            totalgas += gas[i] - cost[i];
            currgas +=  gas[i] - cost[i];

            if(currgas < 0){
                startindex = i + 1;
                currgas = 0;
            }
        }

        return (totalgas >= 0) ? startindex : -1;
    }
};