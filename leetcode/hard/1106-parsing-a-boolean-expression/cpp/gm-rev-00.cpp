// Runtime: 0ms
// Memory: 9.7MB
class Solution {
public:
    bool parseBoolExpr(string expression) {
        std::stack<char> st;

        for(char c : expression) {
            bool sub_and = true;
            bool sub_or = false;
            switch(c) {
            case ')':
                while(st.top() == 't' || st.top() == 'f') {
                    sub_and &= st.top() == 't';
                    sub_or |= st.top() == 't';
                    st.pop();
                }
                if(st.top() == '!') {
                    st.pop();
                    st.push((!sub_and) ? 't' : 'f');
                } else if(st.top() == '&') {
                    st.pop();
                    st.push((sub_and) ? 't' : 'f');
                } else {
                    st.pop();
                    st.push((sub_or) ? 't' : 'f');
                }
                break;
            case ',':
            case '(':
                break;
            default:
                st.push(c);
            }
        }

        return st.top() == 't';
    }
};
