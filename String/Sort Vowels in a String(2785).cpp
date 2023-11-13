class Solution {
public:
bool is_vowel(char c){
if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')    return true;

else return false; 
}
    string sortVowels(string s) {
        int n = s.length();

        vector<int>vowels;

        for(int i = 0; i < n; i++){
            if(is_vowel(s[i])) vowels.push_back(s[i]);
        }

        sort(vowels.begin() , vowels.end());
        
        int idx = 0;
        for(int i = 0; i < n; i++){
              if(is_vowel(s[i])) s[i] = vowels[idx++];
        }
        return s;
    }
};
