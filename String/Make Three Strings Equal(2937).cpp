class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int min_len = min({s1.length(),s2.length(),s3.length()});
        
        int matching_char = 0;
        for(int i = 0; i < min_len; i++){
            
             if(s1[i] == s2[i] && s2[i] == s3[i]) matching_char++;
             else break;
        }
        if(matching_char == 0) return -1; // All the 3 string will never be equal
        
        return s1.length() + s2.length() + s3.length() - (3 * matching_char);
    }
};
