class Solution {
public:

    int operation(vector<int>& nums){

        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> newArray;
        for(int i = 1; i < nums.size(); i++){
            newArray.push_back((nums[i - 1] + nums[i]) % 10);
        }

        return operation(newArray);

    }
    int triangularSum(vector<int>& nums) {
        return operation(nums);
    }
};