/*
  Just checking the condition and performing the operation as mentioned in the question.
  Incrementing or Decrementing if the conditon matched.
  To check every expression Time Complexity:O(n). 
  It is just my first approach what i think first and implemented it.
  */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="--X") --x;
            if(operations[i]=="++X") ++x;
            if(operations[i]=="X--") x--;
            if(operations[i]=="X++") x++;
        }
        return x;
    }
};
