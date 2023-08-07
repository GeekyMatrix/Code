class Solution {
public:
//Recursive
  bool solve(string s1,string s2){
      if(s1==s2) return true;
      if(s1.length()!=s2.length()) return false;

      bool result=false;
        int n=s1.length();

      for(int i=1;i<n;i++){
         /*
            "great", "eatgr"
            i=2
            swapped
            s1.substr(0,i); "gr"  s2.substr(n-i,i) "gr" 
            s1.substr(i,n-i); "eat" s2.substr(0,n-i) "eat" 
         */
   bool swapped=solve(s1.substr(0,i),s2.substr(n-i,i))&&solve(s1.substr(i,n-i),s2.substr(0,n-i));
   if(swapped==true) {
   result= true;
    break;
   }
          
             /*
            "great", "eatgr"
            i=2
            swapped
            s1.substr(0,i); "gr"  s2.substr(0,i) "ea" 
            s1.substr(i,n-i); "eat" s2.substr(i,n-i) "tgr" 
             */
    bool not_swapped=solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i));
   if(not_swapped==true){
   result= true;
    break;
   }
      }
      return result;
  }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }

//Memoization  Method
   unordered_map<string,bool>mp;
   bool solve(string s1,string s2){
      if(s1==s2) return true;
      if(s1.length()!=s2.length()) return false;

      string key=s1+"_"+s2;

      if(mp.find(key)!=mp.end()) return mp[key];

      bool result=false;
        int n=s1.length();

      for(int i=1;i<n;i++){
         /*
            "great", "eatgr"
            i=2
            swapped
            s1.substr(0,i); "gr"  s2.substr(n-i,i) "gr" 
            s1.substr(i,n-i); "eat" s2.substr(0,n-i) "eat" 
         */
   bool swapped=solve(s1.substr(0,i),s2.substr(n-i,i))&&solve(s1.substr(i,n-i),s2.substr(0,n-i));
   if(swapped==true) {
   result= true;
    break;
   }
          
             /*
            "great", "eatgr"
            i=2
            swapped
            s1.substr(0,i); "gr"  s2.substr(0,i) "ea" 
            s1.substr(i,n-i); "eat" s2.substr(i,n-i) "tgr" 
             */
    bool not_swapped=solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i));
   if(not_swapped==true){
   result= true;
    break;
   }
      }
      return mp[key]=result;
  }
    bool isScramble(string s1, string s2) {
      mp.clear();
        return solve(s1,s2);
    }
};
