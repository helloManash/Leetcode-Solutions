class Solution {
public:
    bool isValid(string S) {
        stack<char>stk ;
        for(int i=0;i<S.length();i++){
            if(S[i]=='a'){
                stk.push(S[i]);
            }else if(S[i]=='b'){
                if(stk.empty()==true || stk.top()!='a')return false;
                stk.push(S[i]);   
            }else if(S[i]=='c'){
                if(stk.empty() || stk.top()!='b')return false;
                stk.pop();
                if(stk.empty() || stk.top()!='a')return false;
                stk.pop();
            }else{
                return false;
            }
        }
        return stk.empty()==true; 
    }
};