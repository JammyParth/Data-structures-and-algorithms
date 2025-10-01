class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int exchange = 0;
        int emptybottles = numBottles;

        while(emptybottles >= numExchange){
            emptybottles -= numExchange;
            numExchange++;
            exchange++;
            emptybottles++;
        }

        numBottles += exchange;
        return numBottles;
    }
};