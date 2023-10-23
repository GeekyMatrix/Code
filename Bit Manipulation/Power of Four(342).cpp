class Solution {
public:
//Approach 1
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        while(n != 1){
            if(n % 4 != 0) return false;
            n /= 4;
        }
        return true;
    }

//Approach 2
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        
        int x = (log(n) / log(4));

        if(pow(4,x) == n) return true;
    
        return false;
    }   

//Approach 3
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        
        if((n & (n -1)) == 0 && (n - 1) % 3 == 0) return true;
    
        return false;
    } 
};
