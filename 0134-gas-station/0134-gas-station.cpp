class Solution {
public:

    bool canReach(vector<int>& gas, vector<int>& cost, int index){
        int n = gas.size();

        int possiblegas = 0;

       for(int i = 0; i < n; i++){
            int currindex = (i + index) % n; //for looping through the array.
            possiblegas += gas[currindex] - cost[currindex];
            

            if(possiblegas < 0) return false;
        }

        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        if(n == 1 && gas[0] == cost[0]) return 0;
        for(int i = 0; i < n; i++){
            if(gas[i] > cost[i]){
                if(canReach(gas, cost , i)){
                    return i;
                }
            }
        }

        return -1;
    }
};