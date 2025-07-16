class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        // int mid = start + (end - start) / 2; 
        bool isEven = false;
        if(n % 2 == 0){
            isEven = true;
        }

        int mintotal = 0;
        if(isEven){
            int total1 = 0;
            int total2= 0;
            int pos1 = (n - 1) / 2;
            int pos2 = (n - 1) / 2 + 1;
            int mid1 = nums[pos1];
            int mid2 = nums[pos2];

            for(int i =0; i < n; i++){
                total1 += abs(nums[i] - mid1);
                total2 += abs(nums[i] - mid2);
            }

            mintotal = min(total1 , total2); 
        }

        else{
            int mid = (n - 1) / 2;
            int total3 = 0;
            for(int i =0; i < n; i++){
                total3 += abs(nums[i] - nums[mid]);
            }

            mintotal = total3;
        }


    return mintotal;
    }
};