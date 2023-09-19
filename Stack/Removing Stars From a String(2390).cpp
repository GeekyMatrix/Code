class Solution {
public:
    string removeStars(string st) {
        stack<int>s;
        int n = st.length();

        for(int i = 0; i < n; i++){
           if(st[i]!='*') s.push(st[i]);
            if(st[i] == '*') s.pop();
        }

        string res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
