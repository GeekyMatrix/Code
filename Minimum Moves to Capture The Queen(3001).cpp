class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        //Rook can capture the queen in any case with in two moves
        
        if(a == e || b == f){ //If the row and col of rook is same as the queen the rook can capture it in only 1 move
          //But we have to check that is it bishop in b/w the rook and queen or not
            if(a == e && a == c && (d-b) * (d -f) < 0) return 2;
            if(b == f && b == d && (c - a) * (c - e) < 0) return 2;
            return 1;
        }
            
        if(abs(c - e) == abs(d - f)){ //if bishop and queen in the same diagonal
            if(abs(c-a) == abs(d-b) && (b-f) * (b-d) < 0) return 2; // rook  is in the same diagonal of queen and in b/w the bishop and queen
            
            return 1;
        }
        return 2;
    }
};
