class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        int more;

       for(int i=0; i<nums.size() ; i++){
        
        more = target - nums[i];

        if(map.find(more) != map.end()){
            return {i , map[more]};
        }

        map[nums[i]] = i;
       }

       return {};

    }
};

