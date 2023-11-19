class Solution {
public:
    long long minimumSteps(string s) {
      long long res = 0;
        int one_cnt = 0;
        
        for(auto i : s){
             if(i == '1') one_cnt++;
             else res+=one_cnt;
        }
        return res;
    }
};
