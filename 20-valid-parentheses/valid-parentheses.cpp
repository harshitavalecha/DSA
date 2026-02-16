#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // stack<char> st;

        // for (char ch : s) {
        //     // Push opening brackets
        //     if (ch == '(' || ch == '{' || ch == '[') {
        //         st.push(ch);
        //     } 
        //     else {
        //         // If no opening bracket to match
        //         if (st.empty()) return false;

        //         char top = st.top();
        //         st.pop();

        //         // Check matching pairs
        //         if ((ch == ')' && top != '(') ||
        //             (ch == '}' && top != '{') ||
        //             (ch == ']' && top != '[')) {
        //             return false;
        //         }
        //     }
        // }

        // // Stack must be empty
        // return st.empty();
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] =='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return 0;
                }
                else if(s[i]==')'){
                    if(st.top()!='('){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else if(s[i]=='}'){
                    if(st.top()!='{'){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    if(st.top()!='['){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        return st.empty();
    }
};
