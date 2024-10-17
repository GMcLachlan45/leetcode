#include <iostream>
#include <stack>
#include <string>

bool wellFormed(std::string brackets) {
    std::stack<char> st;
    st.push('.');
    for(char bracket : brackets)
        switch(bracket) {
        case ')':
            if(st.top() == '(')
                st.pop();
            else
                return false;
            break;
        case ']':
            if(st.top() == '[')
                st.pop();
            else
                return false;
            break;
        case '}':
            if(st.top() == '{')
                st.pop();
            else
                return false;
            break;
        default:
            st.push(bracket);
        }

    return st.top() == '.';
}

int main() {
    std::string in = "(((())))";
    std::cout<< "The string " << in << ((wellFormed(in)) ? " is well formed." : " is NOT well formed")<<std::endl;

    in = "()[]{}{()}";
    std::cout<< "The string " << in << ((wellFormed(in)) ? " is well formed." : " is NOT well formed")<<std::endl;

    in = "([)";
    std::cout<< "The string " << in << ((wellFormed(in)) ? " is well formed." : " is NOT well formed")<<std::endl;

    in = "]()";
    std::cout<< "The string " << in << ((wellFormed(in)) ? " is well formed." : " is NOT well formed")<<std::endl;

    in = "(";
    std::cout<< "The string " << in << ((wellFormed(in)) ? " is well formed." : " is NOT well formed")<<std::endl;
}
