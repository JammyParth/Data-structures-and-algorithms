class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_set<int> seen;

        int i = 0;
        int j = 0;
        int n = nums.size();

        int count = 0;
        int maxcount = 0;


        while(j < n){
            

            if(seen.find(nums[j]) == seen.end()){
                seen.insert(nums[j]);
                count += nums[j];
                maxcount = max(maxcount , count);
                j++;
            }

            else{
                seen.erase(nums[i]);
                count -= nums[i];
                i++;
            }
        }

        return maxcount;
    }
};