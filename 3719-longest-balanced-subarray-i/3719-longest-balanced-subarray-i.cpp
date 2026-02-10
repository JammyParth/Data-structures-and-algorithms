class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        //odd = -1
        //even = +1
        //2 5 4 3
        //number = 1 0 1 0, we have to find 0.
        //using set for distinct numbers.
        //we have to keep track of numbers
        
        int n = nums.size();
        int maxsize = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            set<int> st;

            for(int j = i; j < n; j++){

                if(!st.count(nums[j]) && nums[j] % 2 == 0){
                    count++;
                }

                else if(!st.count(nums[j]) && nums[j] % 2 == 1){
                    count--;
                }

                if(count == 0){
                    maxsize = max(maxsize , j - i + 1);
                }

                st.insert(nums[j]);
            }
        }

        return maxsize;
    }
};