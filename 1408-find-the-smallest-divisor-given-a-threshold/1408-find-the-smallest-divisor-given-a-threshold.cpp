class Solution {
public:

    bool isPossible(vector<int>& nums, int threshold, int mid){

        int n = nums.size();
        
        long long sum = 0;
        for(int i= 0; i < n; i++){
            int ops = ceil((double)nums[i] / mid);
            sum += ops;
        }

        return (sum <= threshold);

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int start = 1;
        int end = *max_element(nums.begin() , nums.end());

        int res = end;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isPossible(nums, threshold ,mid)){
                res = mid;
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        return res;
    }
};