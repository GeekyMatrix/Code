class Solution {
public:
   bool canEatAll(vector<int>& piles,int &mid,int h){
       int actualhours=0;

       for(int &x:piles){
           actualhours+=x/mid; //hours

           if(x%mid!=0) actualhours++;
       }
       return actualhours<=h;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r= *max_element(piles.begin(),piles.end());

        while(l<r){
       int mid=l+(r-l)/2; //per hr koko can eat mid no.of bananas

       if(canEatAll(piles,mid,h)) r=mid;

       else l=mid+1; 

        }
        return l;
    }
};
