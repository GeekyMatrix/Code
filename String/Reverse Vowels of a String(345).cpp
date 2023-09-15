class Solution {
public:
 bool isvalid(char ch){
 return (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i'|| ch=='I' || ch=='o'|| ch=='O' || ch=='u'|| ch=='U');
 }
    string reverseVowels(string str) {
        int s = 0;
        int e = str.length()-1;

        while(s < e){
            while(!isvalid(str[s]) && s < e) s++;
            while(!isvalid(str[e]) && s < e) e--;
            swap(str[s++], str[e--]);
        }
        return str;
    }
};
