class Solution {
public:
//Approach 1
    bool backspaceCompare(string s, string t) {
      stack<char> st1, st2;

      for(auto ch : s){
          if(ch == '#'){
              if(st1.empty()) continue;
              else st1.pop();
          }
          else  st1.push(ch);
      }  

      
      for(auto ch : t){
          if(ch == '#'){
              if(st2.empty()) continue;
              else st2.pop();
          }
          else  st2.push(ch);
      }

      while(!st1.empty() && !st2.empty()){
        if(st1.top()!= st2.top()) return false;

        st1.pop();
        st2.pop();
      }
      
      if(!st1.empty() || !st2.empty()) return false; 
      return true;
    }

//Approach2
bool backspaceCompare(string s, string t) {
int m = s.length();
int n = t.length();

int i = m - 1;
int j = n - 1;

int skip_s = 0;
int skip_t = 0;

while( i >= 0 || j >= 0){

while(i >= 0){

    if(s[i] == '#'){
    skip_s++;
    i--;
    }
    else if(skip_s > 0){
        skip_s--;
        i--;
    } 
    else break;
}

while(j >= 0){

    if(t[j] == '#'){
    skip_t++;
    j--;
    }
    else if(skip_t > 0){
        skip_t--;
        j--;
    } 
    else break; 
}
char first = i < 0 ? '$' : s[i];
char second = j < 0 ? '$' :  t[j];

if(first != second) return false;

i--;
j--;

}
return true;
}
};
