class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        stack<int> st;
        int n = nums1.size();
        int m  = nums2.size();
        vector<int> ans;
        unordered_map<int , int> mp;
        for(int i = m - 1; i >= 0; i--)
        {   
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]] = -1;
            }

            else mp[nums2[i]] = st.top(); 
            st.push(nums2[i]);
        }

        for(auto num : nums1){
            ans.push_back(mp[num]);
        }

    return ans;
    }
};