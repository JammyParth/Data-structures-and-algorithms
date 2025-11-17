class Solution {
public:
    int minLengthAfterRemovals(string s) {
        sort(s.begin() , s.end());
        stack<char> st;

        st.push(s[0]);
        int n = s.size();

        int i = 1;
        while(i < n){
            char ch = s[i];
            
            if(!st.empty() && ch != st.top()){
                st.pop();
            }
            

            else{
                st.push(ch);
            }

            i++;
        }

        return st.size();
    }
};