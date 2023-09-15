class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i = 0;

        while(i < s.length()){
            if(s[i] ==' ') i++;

            else{
                string temp="";
                while(i < s.length() && s[i]!=' '){
                    temp+=s[i];
                    i++;
                }
            if(res.length() == 0) res = temp;
            else res = temp +' '+ res;
        }
        }
        return res;
    }
};
