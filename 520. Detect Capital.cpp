/*
    My approach: I iterate through each            character checking the condition given in the question. If checks true we increment the count.At last check whether the count is equal to given word size or not.

*/
Time Complexity:
Only iterating on the size of word so, O(sizeofword).

bool detectCapitalUse(string word) {
        int upperCount=0;
        int lowerCount=0;
        int charcount=1;
        for(int i=0;i<word.size();i++){
            if(word[i]>'A'&& word[i]<'Z') upperCount++;
            if(word[i]>'a'&& word[i]<'z') lowerCount++;
            if((word[0]>'A' && word[0]<'Z')){
                if(word[i]>'a'&& word[i]<'z') charcount++;
            }
    }
    if(upperCount == word.size() || lowerCount==word.size() || charcount==word.size())
        return true;
        return false;
    }