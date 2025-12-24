class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int counter = 1;

        for(auto val : target){

            while(counter != val){
                ans.push_back("Push");
                ans.push_back("Pop");
                counter++;
            }

            ans.push_back("Push");
            counter++;
        }


        return ans;
    }
};