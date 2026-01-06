class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        //
        int n= nums.size();
        int totalsum = 0;
        for(int i = 0; i < n; i++){
            int num = nums[i];

            int count = 0;
            int sum  = 0;
            for(int j= 1; j * j<= num; j++)
            {
                if(num % j == 0){
                    sum += j;
                    count++;
                

                if(j != (num / j)){
                    sum += (num / j);
                    count++;
                }

                }
            }

            if(count == 4){
                totalsum += sum;
            }
        }

        return totalsum;
    }
};