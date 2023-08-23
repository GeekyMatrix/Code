class Solution {
public:
//Approach 1
    string reorganizeString(string str) {

        string res="";
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>pq;

        for(auto i:str) m[i]++;
        
        for(auto i:m) pq.push({i.second,i.first});
        while(pq.size()>=2){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            res+=top1.second;
            res+=top2.second;
            top1.first--;
            top2.first--;
             if(top1.first > 0)
                pq.push(top1);
            
            if(top2.first > 0)
                pq.push(top2);
        }
          if(!pq.empty()){
              if(pq.top().first > 1)
                return "";
          else  res+=pq.top().second;
        }
        return res;
    }
//Approach 2
    string reorganizeString(string str) {
    int n=str.length();
    vector<int>count(26,0);

    int maxfreq=0;
    int charMaxfreq;

    for(char &ch:str){
        count[ch-'a']++;

        if(count[ch-'a']>maxfreq){
            maxfreq=count[ch-'a'];
            charMaxfreq=ch;
        }

        if(count[ch-'a']>(n+1)/2) return "";
    }

  string result=str;
  int i=0;
 
 //Max char freq ko alternate position par daal diya
  while(count[charMaxfreq-'a']>0){
      result[i]=charMaxfreq;
      i+=2;  //alter mai insert karenge
      count[charMaxfreq-'a']--;
  }
 
 //Place rest of the letters in empty slots in alternate fashion
 for(char ch='a';ch<='z';ch++){
     while(count[ch-'a']>0){
         if(i>=n) i=1;

         result[i]=ch;
         i+=2;
         count[ch-'a']--;
     }
 }
   return result;
    }

};
