class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string>res;
        
        int temp = -1;

        for(int i = 0; i < n; i++){

        if(groups[i] != temp) {
            res.push_back(words[i]);
            temp = groups[i];
        }
        
        }
        return res;
    }
};
