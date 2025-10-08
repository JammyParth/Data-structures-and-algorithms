class Solution {
public:

    int solve(vector<int>& nums, int query, vector<int> &prefixsum){

        int n = nums.size();

        int result = -1;
        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(prefixsum[mid] <= query){
                result = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }


        return result + 1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> prefixsum(n , 0);
        prefixsum[0] = nums[0];


        //prefix sum array.
        for(int i = 1; i < n; i++){
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }

        vector<int> ans;

        for(int i =0; i < queries.size(); i++){

            int count = solve(nums, queries[i]  , prefixsum);
            ans.push_back(count);
        }

        return ans;
        
    }
};