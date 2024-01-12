class Solution {
public:
bool vowelCnt(char ch){
 if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch ==  'I' || ch == 'O' || ch == 'U') return true;

return false;
}
    bool halvesAreAlike(string s) {
        int n = s.length();
        int cnt = 0;

        for(int i = 0; i < n/2; i++)     if(vowelCnt(s[i])) cnt++;
        for(int i = n/2; i < n; i++)      if(vowelCnt(s[i])) cnt--;

        return cnt == 0;
    }
};
