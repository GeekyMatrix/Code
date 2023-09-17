class Solution {
public:
 bool isValid(char c){
   if(c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u') return true;
   return false;
 }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int res = 0,count = 0;

        while(j < s.size()){
            if(isValid(s[j])) count++;

            if(j-i+1 == k){
                res = max(res,count);
                if(isValid(s[i])) count--;
                i++;
            }
            j++;
        }
        return res;
    }
};
