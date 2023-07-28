class Solution {
public:
void solve(int index,string output,string digits,string mapping[],vector<string>&ans){
       //BASE CASE
         if(index>=digits.length()){
           ans.push_back(output);
           return;
         }
         int number=digits[index]-'0';
         string value=mapping[number];
         //TAKE THE ith ELEMENT
         for(int i=0;i<value.length();i++){
             output.push_back(value[i]);
             solve(index+1,output,digits,mapping,ans);
             //BACKTRACK
               output.pop_back();
         }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;
        string output;
         string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
          solve(0,output,digits,mapping,ans);
        return ans;

    }
};
