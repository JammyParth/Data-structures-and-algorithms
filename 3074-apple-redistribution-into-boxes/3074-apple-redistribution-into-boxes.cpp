class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int totalapples = 0;

        for(int i = 0; i < n; i++){
            totalapples += apple[i];
        }

        sort(capacity.rbegin() , capacity.rend());
        int m = capacity.size();

        int count = 0;
        for(int i = 0; i < m; i++){
            if(totalapples <= 0){
                break;
            }

            totalapples -= capacity[i];
            count++;
        }


        return count;
    }
};