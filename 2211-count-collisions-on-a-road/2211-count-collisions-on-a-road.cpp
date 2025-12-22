class Solution {
public:
    int countCollisions(string directions) {
        //if R and L then collusion  +2
        //if R and S then collusion  +1
        //if S and L then collusion  +1
        stack<char> st;
        int count = 0;
        int n= directions.size();
        st.push(directions[n - 1]);
        
        for(int i = n - 2; i >= 0; i--){
            char ch = directions[i];

            if(ch == 'S'){
                while(!st.empty() && st.top() == 'L'){
                    st.pop();
                    count++;
                }
                st.push('S');
            }

            else if(ch == 'R'){

                if(!st.empty() && st.top() == 'L'){
                    count += 2;
                    st.pop();


                    while(!st.empty() && st.top() == 'L'){
                        st.pop();
                        count++;
                    }

                    st.push('S');

                }

                else if(!st.empty() && st.top() == 'S'){
                    count++;
                }
            }

            else{
                st.push(ch);
            }
        }

        return count;
    }
};