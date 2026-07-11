class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt0 = 0;


        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt0++;
            }

            else if(nums[i] == 1){
                cnt1++;
            }

            else{
                cnt2++;
            }
        }

        nums.clear();

        while(cnt0 > 0){
            nums.push_back(0);
            cnt0--;
        }

        while(cnt1 > 0){
            nums.push_back(1);
            cnt1--;
        }

        while(cnt2 > 0){
            nums.push_back(2);
            cnt2--;
        }
    }
};