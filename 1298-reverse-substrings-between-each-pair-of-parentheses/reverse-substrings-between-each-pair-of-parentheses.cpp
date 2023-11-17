class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string str = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ')'){
                st.push(s[i]);
            }
            else{
                str = "";
                while(!st.empty() && st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }

                for(int i = 0; i < str.length(); i++){
                    st.push(str[i]);
                }
                str = "";
            }
        }
        str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};