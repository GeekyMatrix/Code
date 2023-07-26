class Solution {
public:
int N;
  double possible(vector<int>& dist,int mid_speed){
    double time=0.0;
    
   for(int i=0;i<N-1;i++){
       double t=(double)dist[i]/(double)mid_speed;
       
       time+=ceil(t);
   }
      time+=(double)dist[N-1]/(double)mid_speed;

      return time;
  }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        N=dist.size();
        int l=1, r=1e7;
         int result=-1;

        while(l<=r){
           int mid_speed=l+(r-l)/2;

           if(possible(dist,mid_speed)<=hour){//With this speed he will take aal the trains and it goes for the search of minimum_spped
          result=mid_speed;
          r=mid_speed-1;
           }
        
        else{  //Not catch the trains with this speed thats means increase the speed
             l=mid_speed+1;
        }

        }
        return result;
    }
};
