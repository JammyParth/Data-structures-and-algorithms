class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {    
        int n = startTime.size();
        vector<int> freetimes;
        freetimes.push_back(startTime[0]);

        for(int i= 1; i < n; i++){
            freetimes.push_back(startTime[i] - endTime[i - 1]);
        } 

        if(eventTime - endTime[n - 1] != 0){
        freetimes.push_back(eventTime - endTime[n - 1]);
        }


        if(freetimes.size() == 0) return 0;

       // int windowsize = k + 1;
        int i = 0;
        int j = 0;
        int currSum = 0;
        int maxSum = INT_MIN;
        
        int m = freetimes.size();

        while(j < m){
            currSum += freetimes[j];


            while(i < m && j - i + 1 > k + 1){
                currSum -= freetimes[i];
                i++;
            }

            maxSum = max(maxSum , currSum);
            j++;
        }


    return maxSum;
    
    }
};