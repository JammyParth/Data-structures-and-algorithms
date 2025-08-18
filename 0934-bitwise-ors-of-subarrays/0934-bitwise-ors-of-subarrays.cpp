// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         int n = arr.size();
//         unordered_set<int> ans;        // stores all distinct ORs overall
//         unordered_set<int> prev, curr; // dp[i-1], dp[i]

//         for (int num : arr) {
//             curr.clear();

//             // Subarray of length 1
//             curr.insert(num);

//             // Extend previous subarrays
//             for (int val : prev) {
//                 curr.insert(val | num);
//             }

//             // Add current results to answer
//             for (int val : curr) {
//                 ans.insert(val);
//             }

//             prev = curr; // Move forward
//         }

//         return ans.size();
//     }
// };



class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> res;
        for (int i = 0; i < n; i++) {
            res.insert(arr[i]);
            for (int j = i - 1; j >= 0; j--) {
                if ((arr[i] | arr[j]) == arr[j]) break;
                arr[j] |= arr[i];
                res.insert(arr[j]);
            }
        }
        return res.size();
    }
};