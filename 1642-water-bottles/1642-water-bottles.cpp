class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        long long totalBottles = numBottles;


        while(numBottles >= numExchange){
            int temp = (numBottles / numExchange);
            numBottles = (numBottles % numExchange) + temp;
            totalBottles += temp;
        }

        return totalBottles;
    }
};