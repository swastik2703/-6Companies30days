// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        //traverse kro puri list ko
        for(auto x : tokens){
            if(x != "+" && x != "-" && x != "*" && x != "/"){
                //means present element is a number
                st.push(stoi(x));
            }
            else{
                //present elment is operator
                long long a = st.top();
                st.pop();

                long long b = st.top();
                st.pop();

                if(x == "+"){
                    st.push(a+b);
                }

                else if(x == "-"){
                    st.push(b-a);
                }

                else if(x == "*"){
                    st.push(b*a);
                }

                else{
                    st.push(b/a);
                }
            }
        }
        return st.top();
        
    }
};