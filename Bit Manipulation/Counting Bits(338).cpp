class Solution {
public:
//TC=O(n log n)
    vector<int> countBits(int n) {
        vector<int> result(n+1);
       
       for(int i=0; i<=n; i++)  result[i]=__builtin_popcount(i);

       return result;
    }

//TC=O(n)
    vector<int> countBits(int n) {
        vector<int> result(n+1);
       result[0]=0; //Binary of 0 has 0 number of bits

       for(int i=1; i<=n; i++)  {
           if(i % 2 != 0) result[i]=result[i/2]+1; // for odd no.

           else  result[i]=result[i/2];  // for Even  no.
       }

       return result;
    }
};
