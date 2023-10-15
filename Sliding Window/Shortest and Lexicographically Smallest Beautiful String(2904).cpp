class Solution {
public:
    //BY SUBSTRING METHOD
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string res;
        
        for(int i = 0; i < n; i++){
            int cnt = 0;
            string curr = "";
            
            for(int j = i; j < n; j++){
             curr+=s[j];
             if(s[j] == '1') cnt++;
             
            if(cnt > k) break;
            
            if(cnt == k){ // valid answer ho skta hai
            if(res.empty() || curr.size() < res.size()) res = curr;
             else if(curr.size() == res.size()) res = min(res , curr);
             }
            } 
        }
        return res;
    }

    //BY 
        string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string res;
        
            int i = 0, j = 0;
            int cnt = 0;
            
        while(j < n){
            if(s[j] == '1') cnt++;
            
            if(cnt == k){ //Possible answer ho skta hai
                
            while(i < n && cnt == k){

             string curr = s.substr(i , j - i + 1);
             
            if(res.empty() || curr.size() < res.size()) res = curr;
             else if(curr.size() == res.size()) res = min(res , curr);
            
            if(s[i] == '1') cnt--;
                i++;
             }
            } 
            
            j++;
        }
        return res;
    }
};
