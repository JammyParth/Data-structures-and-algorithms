class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1ptr = 0;
        int nums2ptr = 0;
        vector<int> temp;

        while(nums1ptr < m && nums2ptr < n){

            // if(nums1[nums1ptr] == 0){
            //     temp.push_back(nums2[nums2ptr]);
            // }
            // if(nums2[nums2ptr] == 0){
            //     temp.push_back(nums1[nums1ptr]);
            // }

            if(nums1[nums1ptr] <= nums2[nums2ptr]){
                temp.push_back(nums1[nums1ptr]);
                nums1ptr++;
            }

            else{
                temp.push_back(nums2[nums2ptr]);
                nums2ptr++;
            }

        }

    while(nums2ptr < n){
        temp.push_back(nums2[nums2ptr]);
        nums2ptr++;
    }


    while(nums1ptr < m){

        temp.push_back(nums1[nums1ptr]);
        nums1ptr++;

    }

    nums1.clear();

    for(int i =0; i< temp.size(); i++){
        nums1.push_back(temp[i]);
    }
    
    }
};