class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        for(auto val : nums1){
            merged.push_back(val);
        }

        for(auto val: nums2){
            merged.push_back(val);
        }

        sort(merged.begin() , merged.end());
        int n = merged.size();
        

        if(n % 2){ //odd elements
            int mid = n / 2;
            return (double)merged[mid];
        }

        else{
            int mid = n / 2;
            return (double)(merged[mid - 1] + merged[mid]) / 2;
        }

    }
};