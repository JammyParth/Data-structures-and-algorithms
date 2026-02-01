class Solution {
public:
    int minimumCost(vector<int>& nums) {
        //finding the smallest and second smallest from behind
        //remove them and then add the first element remaining.

        int n= nums.size();

        int smallest = INT_MAX;
        int second_smallest = INT_MAX;

        int total = 0;
        for(int i = n - 1; i >= 1; i--){
            if(nums[i] < smallest){
                second_smallest = smallest;
                smallest = nums[i];
            }

            else if(nums[i] >= smallest && nums[i] < second_smallest){
                second_smallest = nums[i];
            }
        }


        total += smallest + second_smallest + nums[0];
        return total;

    }
};