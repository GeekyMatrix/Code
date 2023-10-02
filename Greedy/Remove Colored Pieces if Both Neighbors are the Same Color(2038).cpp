class Solution {
public:
    bool winnerOfGame(string colors) {
        int Alice_cnt = 0;
        int Bob_cnt = 0;
        int n = colors.size(); 
        for(int i = 1; i < n-1; i++){
            
            if(colors[i -1] ==  colors[i] && colors[i] == colors[i + 1]){
                if(colors[i] == 'A') Alice_cnt++;
                else Bob_cnt++;
            }
        }
        return Alice_cnt > Bob_cnt ? true : false;
    }
};
