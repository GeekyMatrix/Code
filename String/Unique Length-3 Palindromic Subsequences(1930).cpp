//Approach 1
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        unordered_set<char>unique_letters;
        for(int i = 0; i < n; i++)  unique_letters.insert(s[i]);

        int res = 0;

for(char letter : unique_letters){  // haar ek 3 size element ka left most same idx and right most same idx find karenge
           
           // letter ----->a
           int left_idx = -1;
           int right_idx = -1;

           for(int i = 0; i < n; i++){
               if(s[i] == letter){
                   
                   if(left_idx == -1) left_idx = i;

                   right_idx = i;
               }
           }
           
    unordered_set<char>st;
 for(int middle = left_idx + 1; middle <= right_idx - 1; middle++){ //uss left most & right most same elememt ke bich unique character se different palindrome banega
  
  st.insert(s[middle]);
          }

  res += st.size();
        }
return res;
    }
};

//Approach 2
int countPalindromicSubsequence(string s) {
        int n = s.length();

        int res = 0;

vector<pair<int,int>>indices(26,{-1 , -1});

for(int i = 0; i < n; i++){ // haar ek char ka left most and right most element rakh lega
  char ch = s[i]; 

  int idx = ch - 'a'; // a----> 0 , b---> 1 .......

  if(indices[idx].first == -1) indices[idx].first = i;

  indices[idx].second = i;
}

for(int i = 0; i < 26; i++){  // haar ek 3 size element ka left most same idx and right most same idx find karenge
           
           // letter ----->a
           int left_idx = indices[i].first;
           int right_idx = indices[i].second;

           if(left_idx == -1) continue; // koi index nhi mila hai uska

    unordered_set<char>st;
 for(int middle = left_idx + 1; middle <= right_idx - 1; middle++){ //uss left most & right most same elememt ke bich unique character se different palindrome banega
  
  st.insert(s[middle]);
          }

  res += st.size();
        }
return res;
    }
