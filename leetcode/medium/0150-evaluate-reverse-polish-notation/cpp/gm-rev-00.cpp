// Runtime: 9ms
// Memory: 15.51MB
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for(std::string token : tokens) {
            if(token == "+") {
                int num = st.top();
                st.pop();
                num += st.top();
                st.pop();
                st.push(num);
            } else if(token == "-") {
                int num = st.top();
                st.pop();
                num = st.top() - num;
                st.pop();
                st.push(num);
            } else if(token == "*") {
                int num = st.top();
                st.pop();
                num *= st.top();
                st.pop();
                st.push(num);
            } else if(token == "/") {
                int num = st.top();
                st.pop();
                num = st.top() / num;
                st.pop();
                st.push(num);
            }else
                st.push(std::stoi(token));
        }
        return st.top();
    }
};
