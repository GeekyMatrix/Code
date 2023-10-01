class Solution {
public:
//Approach1 

    string reverseWords(string s) {
        string res = "";
        int n = s.length();
        string temp;

        for(int  i = 0; i < n; i++){
         
         if(s[i]!=' ') temp+=s[i];

        else{ // Space mil gya toh Reverse krdo
        reverse(temp.begin(), temp.end());
        res+=temp+" ";
        temp = "";
         }
        }
        
        reverse(temp.begin(), temp.end()); //last wala word ke liye
        res+=temp;

        return res;
    }

//Approach 2(Two pointer)
string reverseWords(string s) {
int l,r = 0;

while(l < s.size()){ 

 while(r < s.size() && s[r]!= ' ') r++; //Character hai

 reverse(s.begin() + l, s.begin() + r); // Space mil gya toh Reverse krdo

 l = r + 1;
 r = l;
}
return s;
}
};
