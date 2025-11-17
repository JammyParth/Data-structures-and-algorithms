class Solution {
public:

    bool isValid(int mid , vector<int>& houses, vector<int>& heaters){
        int n = houses.size();
        for(int i = 0; i < n; i++){
            int maxrange = houses[i] + mid;
            int minrange = houses[i] - mid;

            auto lowerbound = lower_bound(heaters.begin() , heaters.end(), minrange);

            if(lowerbound == heaters.end()){
                return false;
            }

            if(*lowerbound > maxrange){
                return false;
            }
        }

        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin() , houses.end());
        sort(heaters.begin() , heaters.end());

        int n = houses.size();
        int start = 0;
        int end = max(
            abs(houses.back() - heaters.front()),
            abs(houses.front() - heaters.back())
        );

        int ans = end;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isValid(mid, houses, heaters)){
                ans = mid;
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

    return ans;

    }
};