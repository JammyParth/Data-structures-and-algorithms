class Solution {
public:
    bool check(vector<int> &piles , int k , int h){
        int n = piles.size();
        int count = 0;

        for(int i = 0; i < n; i++){
           
           int temp = piles[i];
           count += ceil((double)temp / k);

           if(count>h){
            return false;
           }
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();

        int limit = *max_element(piles.begin() , piles.end());

        int start = 1;
        int end = limit;
        int res = end;
        while(start <= end){
            int  mid = start + (end - start) /  2;

            if(check(piles , mid , h)){
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