/* 
  Approach: Iterating through every character and counting the letter.
            Returing the answer by doing simple Maths.
            Time Complexity:O(sizeofstring) for iterating over each character.
*/



class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(char &ch:s){
            if(ch==letter){
                count++;
            }
        }
        return (count*100)/s.size();
    }
};
