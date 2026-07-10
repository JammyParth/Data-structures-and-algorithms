class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge(nums , 0  , n - 1);
        return nums;
    }


    //mergesort

    //then I want to sort the divided parts into a temp array

    void mergesort(vector<int> &nums , int start, int mid , int end){

        vector<int> temp;

        int left = start;
        int right = mid + 1;


        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }

            else{
                temp.push_back(nums[right]);
                right++;
            }
        }


        while(left <= mid){
                temp.push_back(nums[left]);
                left++;
        }

        while(right <= end){
                temp.push_back(nums[right]);
                right++; 
        }


        for(int k = start; k <= end; k++){
            nums[k] = temp[k - start]; 
        }
    }

    //first I have to divide the array into parts using recursion


    void merge(vector<int> &nums , int start, int end){

        if(start >= end){
            return;
        }

        int mid = start + (end - start) / 2;

        merge(nums, start , mid);
        merge(nums , mid + 1, end);


        mergesort(nums, start, mid , end);
    }
};