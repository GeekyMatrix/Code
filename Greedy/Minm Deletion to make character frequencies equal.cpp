class Solution {
public:
//Approach 1
    int minDeletions(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(int i=0 ; i<n; i++) freq[s[i]-'a']++; //Frequency store krwa li
        
         int res=0;
         unordered_set<int>st;
        
        for(int i=0;i<26;i++){
        while(freq[i]>0 && st.find(freq[i])!=st.end()){ // uski freq already present hai set mai
         freq[i]--;
         res++;
        }
        st.insert(freq[i]);
        }
           return res;
    } 

//Approach 2
 int minDeletions(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(int i=0 ; i<n; i++) freq[s[i]-'a']++; //Frequency store krwa li
        sort(freq.begin(),freq.end());  ///same freq wale ko ek place pr krdo

         int res=0;
    for(int i=24; i>=0; i--){
        if(freq[i] >= freq[i+1]){   
             int prev=freq[i];
             freq[i] = max(0,freq[i+1]-1);
             res +=prev-freq[i];
        }
    }
    return res;
 }
};
