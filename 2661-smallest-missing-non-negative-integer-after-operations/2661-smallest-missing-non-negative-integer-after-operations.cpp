// class Solution {
// public:

//     int findSmallestInteger(vector<int>& nums, int value) {
//         int n = nums.size();

//         set<int> mex;
//         int counter = 0;
//         for(int i = 0; i < n; i++){
            
//             int lastval = nums[i];

//             if(lastval < 0){
//                 lastval = (((lastval % value) + value) % value);
//             }
            
//             else{
//             lastval = abs(nums[i]) % value;
//             }

//             int temp = lastval;

//             while(mex.count(temp)){
//                 temp += value;
//             }

//             mex.insert(temp);
//         }

//         for(auto val : mex){
//             if(counter == val){
//                 counter++;
//             }
//         }

//         return counter;
//     }
// };

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> cnt;

        // Count frequency of each residue modulo 'value'
        for (int x : nums) {
            long long r = x % value;
            if (r < 0) r += value; // make it in [0, value-1]
            cnt[(int)r]++;
        }

        int x = 0;
        while (true) {
            int r = x % value;
            if (cnt[r] == 0) {
                // We cannot form 'x', so it's the mex
                return x;
            }
            // Use one number with this remainder to form 'x'
            cnt[r]--;
            x++;
        }
    }
};
