/*
  Simple Appproach: Just iterating from left to right and counting all the set bits of that number and check if it prime or not if check true increment it in answer else not.
  Time Complexity: To iterating from left to right O(n) to find prime number it's O(sqrt(n)) Therefor the overall time complexit is: O(n*sqrt(n))
*/
class Solution {
public:
    bool checkPrime(int n){
        if(n==0 || n==1) return false;
       for(int i=2;i<=sqrt(n);i++){
        if(!(n%i)) return false;
    }
    return true;
    }
    int countPrimeSetBits(int left, int right) {
            int ans=0;
        for(int i=left;i<=right;i++){
              int countsetbits=0;
              int x=i;
              while(x){
                if(x&1) countsetbits++;
                x=x>>1;
              }
              if(checkPrime(countsetbits)) ans++;
        }
        return ans;
    }
};
