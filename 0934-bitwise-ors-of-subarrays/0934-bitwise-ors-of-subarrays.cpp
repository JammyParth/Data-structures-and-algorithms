class Solution {
public:

    int subarrayBitwiseORs(vector<int>& arr) {
        // vector<int> temp;

        // for(int i = 1; i < arr.size(); i++){
        //     if(arr[i] != arr[i - 1]){
        //         temp.push_back(arr[i]);
        //     }
        // }
        int n = arr.size();
        set<int> results, prev, curr;

        for(int i= 0; i < n; i++){

                for(auto x : prev){
                    curr.insert(arr[i] | x);
                    results.insert(arr[i] | x);
                }

                curr.insert(arr[i]);
                results.insert(arr[i]);
                prev = curr;
                curr.clear();
        }

        return results.size();

    }
};