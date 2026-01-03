class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map and heap.
        int n = nums.size();
        unordered_map<int , int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>> heap;

        for(auto val : mp){
            heap.push({val.second , val.first});
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }



    return ans;
    }
};