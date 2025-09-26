class Solution {
public:

    // bool isValid(int num1, int num2, int num3){

    //     if((num1 + num2 > num3) && (num1 + num3 > num2) && (num2 + num3 > num1)){
    //         return true;
    //     } 

    //     return false;
    // }


    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;

        if(n < 3) return 0;
        sort(nums.begin() , nums.end());


        for(int k = n - 1; k >= 2; k--){
            int i = 0;
            int j = k - 1;


            while(i < j){
            if(nums[i] + nums[j] > nums[k]){
                //all pairs between i and j are valid
                cnt += (j - i);
                j--;
            }
            else{
                i++;
            }
            }
        }
        return cnt;
    }
};