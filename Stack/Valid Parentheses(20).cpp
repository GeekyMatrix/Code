class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s){
        if(!st.empty()){
         if(st.top()=='('&&x==')'||st.top()=='['&&x==']'||st.top()=='{'&&x=='}') {
           st.pop();
           continue;
        }
        }
        st.push(x);
        }
       return st.empty()?true:false;
    }
};
