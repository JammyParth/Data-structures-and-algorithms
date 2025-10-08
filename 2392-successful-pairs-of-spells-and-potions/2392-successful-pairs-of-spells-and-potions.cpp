class Solution {
public:

    int solve(vector<int>& potions , int spell, long long success){

        int n = potions.size();
        int result = -1;
        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(1LL * potions[mid] * spell >= success){
                result = mid;
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        return result;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> ans;
        sort(potions.begin() , potions.end());

        int n = potions.size();
        for(int i = 0; i < spells.size(); i++){
            int count = 0;
            int res = solve(potions , spells[i] , success);

            if(res != -1){
                count = (n - res);
            }
            ans.push_back(count);

        }


       return ans;
        
    }
};