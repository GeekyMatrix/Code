class Solution {
public:
// //Recursive method
//  //Time: O(n*(2^min(n,k))), Space: O(n)
    int solve(int k, int n){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        int mn = INT_MAX;
        
        for(int i=1; i<=n; i++){
            
            /*representing both the choices
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            int temp = 1 + max(solve(k-1, i-1), solve(k, n-i));
            
            mn = min(mn, temp);  //minimum number of attempts
        }
        return mn;
    }

    int superEggDrop(int k, int n) {
       //k means number of eggs, n means number of floors
        return solve(k, n);
    }

//Memoization method
 //Time: O(n^2*k), Space: O(n*k)
 
 int t[101][10001];

    int solve(int k, int n){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(t[k][n]!=-1) return t[k][n];
         int mn = INT_MAX;
        
        for(int i=1; i<=n; i++){
            
            /*representing both the choices
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            int temp = 1 + max(solve(k-1, i-1), solve(k, n-i));
            
            mn = min(mn, temp);  //minimum number of attempts
        }
        return t[k][n]=mn;
    }

    int superEggDrop(int k, int n) {
       //k means number of eggs, n means number of floors
       memset(t,-1,sizeof(t));
        return solve(k, n);
    }

//Optimised Memoization method
 //Time: O(n^2*k), Space: O(n*k)

 int t[101][10001];

    int solve(int k, int n){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(t[k][n]!=-1) return t[k][n];
         int mn = INT_MAX;
        
        for(int i=1; i<=n; i++){
            
                
            /*here is the optimization goes on, the basic idea is before 
            any function call we are checking if any value from that function 
            call is present or not*/
            int low = 0, high = 0;

            if(t[k-1][i-1]!=-1) low=t[k-1][i-1]; 
            else {
              low=solve(k-1,i-1);
              t[k-1][i-1]=low;
            }

              if(t[k][n-i]!=-1) high=t[k][n-i]; 
            else {
              high=solve(k,n-i);
              t[k][n-i]=high;
            }
            int temp=1+max(low,high);

            
            mn = min(mn, temp);  //minimum number of attempts
        }
        return t[k][n]=mn;
    }

    int superEggDrop(int k, int n) {
       //k means number of eggs, n means number of floors
       memset(t,-1,sizeof(t));
        return solve(k, n);
    }
  
//Memoization + Binary Search Method

 int t[101][10001];

    int solve(int k, int n){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(t[k][n]!=-1) return t[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            
            int left = solve(k-1, mid-1);
            int right = solve(k, n-mid);
            
            temp = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     //move to the downward
    
            mn = min(mn, temp); //minimum number of attempts
        }
        return t[k][n] = mn;
    }

    int superEggDrop(int k, int n) {
       //k means number of eggs, n means number of floors
       memset(t,-1,sizeof(t));
        return solve(k, n);
    }
};
