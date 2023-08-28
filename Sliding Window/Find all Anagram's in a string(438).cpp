class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
          vector<int>ans;
        int len_s=s.size();
        int len_p=p.size();

        if(len_p>len_s) return ans;

        vector<int>p_freq(26,0);
        vector<int>window(26,0);

        for(int i=0;i<len_p;i++){   //First Window
            p_freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }

        if(p_freq==window) ans.push_back(0);
       
       for(int i=len_p;i<len_s;i++){   //FOR INCLUDE THE CURRENT && EXCLUDE THE PREVIOUS ONE
    
           window[s[i-len_p]-'a']--;         //EXCLUDE
         
           window[s[i]-'a']++;               //INCLUDE

           if(p_freq==window) ans.push_back(i-len_p+1);  
       }

      return ans;
    }
};
