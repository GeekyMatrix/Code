class Solution {
public:
//Approach-1 (Using Brute Force) - ACCEPTED
//T.C : O(n^2)
//S.C : O(1)
  int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        int n = s.length();
        
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j<n; j++) {
                
                if(s[i] == s[j]) {
                    result = max(result, j-i-1);
                }
            }
        }
        
        return result;
    }

//Approach-2 (Using Hashmap) - ACCEPTED
//T.C : O(n)
//S.C : O(n)
    int maxLengthBetweenEqualCharacters(string s) {
        int Maxi = -1;
        int n = s.length();
        
        unordered_map<char,int>mp;

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(mp.find(ch) == mp.end()) mp[ch] = i;
            
           else Maxi = max(Maxi , i - mp[ch] - 1);

        }  
     return Maxi;
    }

//Approach-3 (Using integer array instead of map)
//T.C : O(n)
//S.C : O(26) ~ O(1)
    int maxLengthBetweenEqualCharacters(string s) {
        int Maxi = -1;
        int n = s.length();
        
        vector<int>cnt(26,-1);

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(cnt[ch - 'a'] == -1) cnt[ch - 'a'] = i;
            
           else Maxi = max(Maxi , i - cnt[ch - 'a'] - 1);

        }  
     return Maxi;
    }
};
