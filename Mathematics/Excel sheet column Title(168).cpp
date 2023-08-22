class Solution {
public:
 string convertToTitle(int N) {
      string ans;
      while(N>0){
          N--;
          int remainder=N%26;
          char ch=remainder+'A';
           ans=ch+ans;
          N/=26;
      }
     return ans;
 }
};
