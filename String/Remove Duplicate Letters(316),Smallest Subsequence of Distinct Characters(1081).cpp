class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        int n = s.length();
        vector<int>lastindex(26);
        vector<bool>taken(26,false);

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            lastindex[idx] = i;
        }
        for(int i = 0; i < n;i++){
            char ch = s[i];
         int idx = ch - 'a';

         if(taken[idx] == true) continue;

         //lexicographical order maintain ke liye   
       while(result.length() > 0 && result.back() > ch && lastindex[result.back() - 'a'] > i){ 
         taken[result.back() - 'a'] = false;
         result.pop_back();
        }

        result.push_back(ch); //uss element ka push krdo
        taken[idx] = true;    // uska taken mai bhi mark true krdo
        }
        return result;
    }
};
