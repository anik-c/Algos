/* Performed as condition mentioned in the question only iterating and checking.
  Time Complexity:O(N^2)
*/
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int count=0;
        for(int i=0;i<batteryPercentages.size();i++){
            if(batteryPercentages[i]>0){
                count++;
                for(int j=i;j<batteryPercentages.size();j++){
                    batteryPercentages[j]--;
                }
            }
        }
        return count;
    }
};
