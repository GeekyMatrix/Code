class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(guess(mid) == 0) return mid;
            if(guess(mid)== -1) e = mid-1;
            else if(guess(mid) == 1) s = mid+1;
        }
        return -1;
    }
};
