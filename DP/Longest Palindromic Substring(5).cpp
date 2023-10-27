class Solution {
public:
//Recursive
//TC = O(N^3) 
//SC = O(1)
bool isPalindrome(string s , int i, int j){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0, start_idx = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
             if(isPalindrome(s , i , j)){ //palindrome hai
               if(j - i + 1 > max_len){   // maximum length hai
                   max_len = j - i + 1;
                   start_idx = i;
               }
             }
            }
        }
        return s.substr(start_idx , max_len);
    }

//Memoization
//TC = O(N^2)
//SC = O()
int t[1001][1001];
bool solve(string &s , int i, int j){
    if(i >= j) return 1;
    
    if(t[i][j] != -1) return t[i][j];
    
    if(s[i] == s[j]) return t[i][j] = solve(s , i + 1, j - 1);

    return t[i][j] = 0;
}
    string longestPalindrome(string s) {
        int n = s.size();
        memset(t , -1 , sizeof(t));

        int max_len = 0, start_idx = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
             if(solve(s , i , j)){ //palindrome hai
               if(j - i + 1 > max_len){   // maximum length hai
                   max_len = j - i + 1;
                   start_idx = i;
               }
             }
            }
        }
        return s.substr(start_idx , max_len);
    }
};
