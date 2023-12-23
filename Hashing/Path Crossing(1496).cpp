class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>>s;
        int x = 0, y = 0;
        s.insert({0,0}); //Origin

        for(char i : path){

            if(i == 'N') y++;
            else if(i == 'E') x++;
            else if(i == 'S') y--;
            else if(i == 'W') x--;

            if(s.find({x,y}) != s.end()) return true; //  path crosses itself at any point   

            s.insert({x,y});
        }
        return false;
    }
};
