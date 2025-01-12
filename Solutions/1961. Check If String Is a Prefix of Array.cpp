/*
      Approach is simple just add the every string in the given vector and check whether it is same as given strinng or not.
      Now, return true if condition matches else return false.
      Time Complexity: O(n)
*/


class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++){
            ans+=words[i];
            if(ans==s) return true;
        }
        return false;
    }
};
