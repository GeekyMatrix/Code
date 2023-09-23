class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>res;
        sort(potions.begin(),potions.end());

        for(int i = 0; i < spells.size(); i++){
          int cnt = 0;
          int l = 0, r = potions.size()-1;

          while(l <= r){
              int mid = l+(r-l)/2;
              if(spells[i] * 1ll * potions[mid] >=success){ //1ll is securely interger overflow
                  cnt = potions.size() - mid;
                  r = mid - 1;
              }
              else l = mid + 1;
          }
          res.push_back(cnt);
        }
        return res;
    }
};
