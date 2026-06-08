class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        int count = 0;

        for(auto val : nums){
            if(val > pivot){
                larger.push_back(val);
            }

            else if(val < pivot){
                smaller.push_back(val);
            }

            else{
                count++;
            }
        }


        vector<int> res = smaller;

        for(int i = 0; i < count; i++){
            res.push_back(pivot);
        }

        if(!larger.empty()){
            res.insert(res.end() , larger.begin() , larger.end());
        }

        return res;

    }
};