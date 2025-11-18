class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;   // use long long to be safe for intermediate results

        for (string &tok : tokens) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;

                if (tok == "+") {
                    res = a + b;
                } else if (tok == "-") {
                    res = a - b;
                } else if (tok == "*") {
                    res = a * b;
                } else { // "/"
                    // C++ integer division already truncates toward 0 as required
                    res = a / b;
                }

                st.push(res);
            } else {
                // token is a number
                st.push(stoi(tok));
            }
        }

        return (int)st.top();

    }
};