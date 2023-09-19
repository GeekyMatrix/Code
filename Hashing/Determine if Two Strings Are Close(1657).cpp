class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n!=m) return false;
        vector<int>freq1(26);
        vector<int>freq2(26);

        for(int i = 0; i<n; i++){
            int idx1 = word1[i]-'a';
            freq1[idx1]++;   // Frequency store krra diya

            int idx2 = word2[i]-'a';
            freq2[idx2]++;  // Frequency store krra diya
        }

        for(int i = 0; i<26; i++){   //1st point =>jo char word1 mai hai wo word2 mai bhi hona chaiye
            if(freq1[i]!=0 && freq2[i]!=0) continue;
             if(freq1[i]==0 && freq2[i]==0) continue;
             else return false;  
        }
        // 2nd point=> Match freq
         sort(freq1.begin(),freq1.end());
         sort(freq2.begin(),freq2.end());

         return freq1 == freq2;
    }
};
