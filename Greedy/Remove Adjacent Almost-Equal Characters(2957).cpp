class Solution {
public:
    bool isAdj(char ch1 , char ch2){
     if(ch1 == ch2) return true;
     if(ch1 + 1 == ch2 || ch1 == ch2 + 1) return true;
        
        return false;
    }
    int removeAlmostEqualCharacters(string word) {
        int res = 0;
        int n = word.length();
        
            int i = 1;
        while(i < n){
            if(isAdj(word[i] , word[i-1]))
            {
                res++;
                i++;
            }
            i++;
        }
        return res;
    }
    
};
