class Solution {
public:

    // bool isValid(vector<int> &a){

    //     vector<int> res;

    //     for(int i = 1; i < a.size(); i++){
    //         res.push_back((a[i] + a[i - 1]) % 2);
    //     }

    //     for(int i = 1;i < res.size(); i++){
    //         if(res[i] != res[i - 1]){
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // void solve(vector<int>& nums ,vector<int> &picked,  int index, int &longestvalid){

    //     int n = nums.size();

    //     if(index == n){
    //         if(isValid(picked)){
    //             int m = picked.size();
    //             longestvalid = max(longestvalid , m);
    //         }
    //         return;
    //     }

    //     picked.push_back(nums[index]);
    //     solve(nums , picked, index + 1 , longestvalid);
    //     picked.pop_back();
    //     solve(nums , picked, index + 1 , longestvalid);
        
    // }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
    //     int longestvalid = 0;
    //     vector<int> picked;

    //     solve(nums, picked, 0 , longestvalid);

    //     return longestvalid;

    // }


    //first let's take the odd count-
    //1
    int oddcount = 0;
    //2
    int evencount = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] % 2 == 0){
            evencount++;
        }
        else{
            oddcount++;
        }
    }


    //even odd parity
    int alternating = 1;
    int parity = nums[0] % 2;

    for(int i = 1; i < n;i++){
        int currparity = nums[i] % 2;

        if(currparity != parity){
            alternating++;
            parity = currparity;
        }
    }


    return max({oddcount, evencount , alternating});
    }

};