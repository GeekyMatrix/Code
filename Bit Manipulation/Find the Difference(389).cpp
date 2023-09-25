class Solution {
public:
//TC = O(N)
//SC = O(1)
    char findTheDifference(string s, string t) {
    int sum_s = 0;

     for(auto i:s) sum_s+=i;
      int sum_t = 0;
     for(auto i:t) sum_t+=i;

     return (char) (sum_t - sum_s);
    }

//TC = O(N)
//SC = O(1)
    char findTheDifference(string s, string t) {
    int temp = 0;

     for(auto i:s) temp ^=i;
     for(auto i:t) temp ^=i;

     return (char)temp;
    }

//TC = O(N)
//SC = O(N)
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        char res;

        for(auto i:s) m[i]++;
        for(auto i:t){
            m[i]--;
            if(m[i] == 0) m.erase(i);
        }
        return m.begin()->first;
    }

//TC = O(NlogN)
//SC = O(1)
     char findTheDifference(string s, string t) {
       sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       int n = s.size();

       for(int i = 0; i<n; i++){
           if(s[i]!=t[i]) return t[i];
       }
      return t.back();
     }
};
