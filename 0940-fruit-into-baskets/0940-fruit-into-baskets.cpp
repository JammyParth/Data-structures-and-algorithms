class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //we have to get longest subarray of 2 distinct elements.
        int n = fruits.size();

        unordered_map<int , int> mp;
        int left = 0;
        int maxcount = 0;

        for(int right = 0; right < n; right++){
            mp[fruits[right]]++;
    
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            maxcount = max(maxcount , right - left + 1);
        }
    
    return maxcount;
    }
};