class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;

        while(i < n){
         char curr_char = chars[i];
         int count = 0;

         while(i < n && chars[i] == curr_char) { //Find the duplicates elements
             count++;
             i++;
         }

         chars[index] = curr_char; //Do the assign work
         index++;

         if(count > 1) {
          string count_str = to_string(count);
         
         for(char &ch:count_str){ //For count more than 10 
          chars[index] = ch;
          index++;
         }
        }
        }
        return index;
    }
};
