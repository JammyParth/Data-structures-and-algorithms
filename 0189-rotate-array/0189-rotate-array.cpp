class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        
        int n = nums.size();
        k = k % n;
        
        vector<int> first_half;
        vector<int> second_half;

        for(int i = 0; i < n - k; i++){
            first_half.push_back(nums[i]);
        }

        for(int i = n - k; i < n; i++){
            second_half.push_back(nums[i]);
        }

        nums.clear();
        nums.insert(nums.end() , second_half.begin() , second_half.end());
        nums.insert(nums.end() , first_half.begin()  ,  first_half.end());
    }
};