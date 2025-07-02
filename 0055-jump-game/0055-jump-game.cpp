class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int maxindex = nums[0];

        for(int i = 1; i < n; i++){
            
            //if we go to the index where we can't go then return false
            if(i > maxindex){
                return false;
            }

            //if we can take a bigger jump to the maxindex then update it
            if(i + nums[i] > maxindex){
                maxindex = i + nums[i];
            }

            //else just continue (not necessary)
            if(i + nums[i] <= maxindex){
                continue;
            }
        }
    return true;
    }
};