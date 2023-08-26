class Solution {
public:
// //Approach 1
// //TC=O(N^2)
//SC=O(N)

    int trap(vector<int>& height) {
        int n=height.size();
        int water_area=0;

       for(int i=1;i<n-1;i++){    // i==0  && i==n-1 they not contain water

    // lmax(left maxm) && rmax(right maxm) uss particular element ke liye water contain krega
        int lmax=height[i];

        for(int j=0;j<i;j++) lmax=max(lmax,height[j]);
        
        int rmax=height[i];
        
         for(int j=i+1;j<n;j++) rmax=max(rmax,height[j]);

         water_area += (min(lmax,rmax))-height[i];
       }
        return water_area;
    }

//Approach 1
//TC=O(N)
//SC=O(N)
    int trap(vector<int>& height) {
        int n=height.size();
          
       vector<int>lmax(n); 
       lmax[0]=height[0];
         
         for(int i=1;i<n;i++) {   // apne index se left side tk maxm store krke rkhega 
         int temp=max(lmax[i-1],height[i]);
         lmax[i]= temp;
         }

         vector<int>rmax(n); 
         rmax[n-1]=height[n-1];
         
         for(int i=n-2;i>=0;i--) {  // apne index se right side tk maxm store krke rkhega 
         int temp=max(rmax[i+1],height[i]);
         rmax[i]= temp;
         }

        int water_area=0;

      for(int i=1;i<n-1;i++)  water_area += (min(lmax[i],rmax[i]))-height[i];

        return water_area;
    }
};
