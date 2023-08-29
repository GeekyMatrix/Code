class Solution {
public:
//BRUTE FORCE
//TC:-O(N^2)
//SC:-O(N)
    int bestClosingTime(string customers) {
         int n=customers.length();
          
          int mini_plenty=INT_MAX;
          int mini_hrs=INT_MAX;

         for(int i=0;i<n;i++){
                int Plenty_cnt=0;
      
             for(int j=0;j<i;j++){
                   if(customers[j]=='N') Plenty_cnt++;  //open hai shop toh plenty dekho
             }

             for(int j=i;j<n;j++){
                 if(customers[j]=='Y') Plenty_cnt++;  //plenty dekho for closed hai shop toh 
             }

             if(Plenty_cnt < mini_plenty ){
                 mini_plenty=Plenty_cnt;
                  mini_hrs=i;
             }
            //Trying Closing at nth hour
               //0 to n-1 shop open -'N'
               int nthHourplenty=count(customers.begin(),customers.end(),'N');
               if(nthHourplenty < mini_plenty) mini_hrs=n;
         }
         return  mini_hrs;
    }

//BETTER APPROACH (prefix sum)
//TC:-O(N)
//SC:-O(N)
 int bestClosingTime(string customers) {
    int n=customers.length();

  vector<int>prefixN(n+1,0);
  prefixN[0]=0;

  vector<int>suffixY(n+1,0);
  suffixY[n]=0;

  for(int i=1;i<=n;i++){
      if(customers[i-1]=='N')   prefixN[i]= prefixN[i-1]+1;
     else prefixN[i]= prefixN[i-1];
  }
 
 for(int i=n-1;i>=0;i--){
     if(customers[i]=='Y') suffixY[i]=suffixY[i+1]+1;
     else suffixY[i]=suffixY[i+1];
 }

           int mini_plenty=INT_MAX;
          int mini_hrs=INT_MAX;
  
  for(int i=0;i<=n;i++) {
      int Plenty_cnt=prefixN[i]+suffixY[i];

            if(Plenty_cnt < mini_plenty ){
                 mini_plenty=Plenty_cnt;
                  mini_hrs=i;
               }
  }
  return mini_hrs;
 }

//OPTIMISE APPROACH (Sliding window)
//TC:-O(N)
//SC:-O(1)

  int bestClosingTime(string customers) {

  int n=customers.length();

  int  mini_hrs=0;
  int  Plenty_cnt=(customers.begin(),customers.end(),'Y');

  int mini_plenty= Plenty_cnt;

  for(int i=0 ;i<n; i++){
      if(customers[i] == 'Y') Plenty_cnt--;
      else Plenty_cnt++;

              if(Plenty_cnt < mini_plenty ){
                 mini_plenty=Plenty_cnt;
                  mini_hrs=i+1;
               }
  }
  return mini_hrs;
  }
};
