class Solution {
public:

    bool validDays(vector<int>& bloomDay, int m, int k, int key){
        
    int bouquets = 0, flowers = 0;

    for (int day : bloomDay) {
        if (day <= key) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
    }

    return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();

        if(n < (long long)m * k){
            return -1;
        }

        int start = 1;
        int end = *max_element(bloomDay.begin() , bloomDay.end());
        int res = end;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(validDays(bloomDay, m , k , mid)){
                res = mid;
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        return res;

    }
};