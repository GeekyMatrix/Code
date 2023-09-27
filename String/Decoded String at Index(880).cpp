class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string res;
        int n = s.size();

        long long size = 0;

//step 1 (size nikalo)
        for(char &ch : s){
            if(isdigit(ch))  size = size * (ch - '0');  //Number
            else size++;    //character
        }
//step 2 (piche se start krro)

 for(int i = n-1; i >=0; i--){
     k = k % size;

     if( k == 0 && isalpha(s[i])) return string(1,s[i]); // we got the kth string

     if(isalpha(s[i]))  size--;  // Decrese the size if its character

     else size = size / (s[i] - '0');   //Decrese the size if its number
 }
 return"";
    }
};
