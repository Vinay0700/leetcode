class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int reqfuel=0;
        int extrafuel=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            extrafuel+=(gas[i]-cost[i]);
            if(extrafuel<0){
                start = i+1;
                reqfuel+=extrafuel;
                extrafuel=0;
            }
        }
        if(reqfuel+extrafuel>=0) return start;
        return -1;
    }
};