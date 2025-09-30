class Solution {
public:

    bool canEat(vector<int>& piles, int h, int speed){

        int n = piles.size();
        int temp = h;
        for(int i = 0; i < piles.size(); i++){
            
            temp -= ceil((double)piles[i] / speed);

        }

        return (temp >= 0);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin() , piles.end());

        int result = end;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(canEat(piles, h , mid)){
                result = mid;
                end = mid - 1;
            }
            
            else{
                start = mid + 1;
            }
        }


        return result;
        
    }
};