class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxheap;
        int n = nums.size();

        if(n < k){
            return {};
        }

        for(int i = 0; i < k; i++){
            maxheap.push({nums[i]  , i});
        }

        vector<int> ans;
        ans.push_back(maxheap.top().first);

        for(int i = k; i < n; i++){
    
            maxheap.push({nums[i] , i});

            //now we have to remove all the highest values which are smaller than i - k

            while(maxheap.top().second <= i - k){
                maxheap.pop();
            }

            ans.push_back(maxheap.top().first);
        }

        return ans;
    }
};