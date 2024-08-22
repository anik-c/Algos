/* 
    Approach: Check every bit from LSB if it is 1 then 
        add ->0*pow(2,power) , power is the current bit position from LSB.
        if 0 then
        add->1*pow(2,power), power is the currrent bit position from LSB.
        Time Complexity: On each iteration the give input is right shifted by 1 so overall Time Complexity is O(log(n)).
*/
class Solution {
public:
    int findComplement(int num) {
    int ans = 0;
    int power = 0;
    if (num == 0)
    {
        return 1;
    }
    else
    {
        while (num != 0)
        {
            if (num & 1) // check the last bit is 1 or 0
            {
                // if last bit is 1 then it must be complemented and add to answer
                ans += 0 * pow(2, power); 
            }
            else
            {
              // if last bit is 0 then it must be complemented and add to answer.
                ans += 1 * pow(2, power);
            }
            power++;
            num = num >> 1;
        }
    }
    return ans;
    }
};
