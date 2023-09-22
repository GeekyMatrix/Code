class Solution {
public:
//Brute force
bool removeSenator(string senate, char ch, int idx){
 bool checkRemovalleftside = false;
 while(true){
    if(idx == 0) checkRemovalleftside = true;

    if(senate[idx] == ch) {
        senate.erase(senate.begin() + idx); //shift
        break;
    }
  idx=(idx+1)%(senate.length()); 
 }
 return checkRemovalleftside;
}

    string predictPartyVictory(string senate) {
        int R_cnt = count(senate.begin(),senate.end(),'R');
        int D_cnt = senate.length() - R_cnt;
        int idx = 0;

        while(R_cnt > 0 && D_cnt > 0){

            if(senate[idx] == 'R'){
            bool checkRemovalleftside = removeSenator(senate, 'D', (idx+1)%(senate.length())); 
            D_cnt--;
             if(checkRemovalleftside) idx--;
            }

            else{ //senate[idx] == 'D'
             bool checkRemovalleftside = removeSenator(senate, 'R', (idx+1)%(senate.length()));
             R_cnt--;
             if(checkRemovalleftside) idx--;
            }

            idx = (idx+1)%(senate.length());

        }
        return R_cnt == 0 ? "Dire" : "Radiant";
    }

//2nd Approach
 void removeSenator(string senate, vector<bool>&removed, char ch, int idx){
 while(true){
    if(senate[idx] == ch && removed[idx] == false) {
        removed[idx] = true;
        break;
    }
    idx=(idx+1)%(senate.length()); 
 }
}

    string predictPartyVictory(string senate) {
        int n = senate.length();
        int R_cnt = count(senate.begin(),senate.end(),'R');
        int D_cnt = senate.length() - R_cnt;
        int idx = 0;
        vector<bool>removed(n,false);  //No one is removed yet

        while(R_cnt > 0 && D_cnt > 0){

            if(removed[idx] == false){

            if(senate[idx] == 'R'){
            removeSenator(senate, removed, 'D', (idx+1)%n); 
            D_cnt--;
            }

            else{ //senate[idx] == 'D'
            removeSenator(senate, removed, 'R', (idx+1)%n);
             R_cnt--;
            }
         }
            idx = (idx+1) % n;
            
        }
        return R_cnt == 0 ? "Dire" : "Radiant";
    }

//queue approach
string predictPartyVictory(string s) {
queue<int>radiantQ,DireQ;
 //Respective wise queue mai index store krlo sbka

 for(int i = 0; i<s.size(); i++){
     if(s[i] == 'R') radiantQ.push(i);
     else DireQ.push(i);
 }
 while(!radiantQ.empty() && !DireQ.empty()){
     int ri = radiantQ.front();
      radiantQ.pop();

      int di = DireQ.front();
      DireQ.pop();

      if(ri < di) radiantQ.push(ri + s.size());
      else DireQ.push(di + s.size());
 }
   return (radiantQ.size() > DireQ.size() ? "Radiant" : "Dire");
 }
};
