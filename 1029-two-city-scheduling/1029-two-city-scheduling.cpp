bool comparator ( vector <int> &a, vector <int> &b ){
    if( a[0] - a[1]  < b[0] - b[1]) return true; // sort by difference in cost
    else return false;
}

class Solution {
public:   
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        int n=costs.size();
        vector<int> diff;
        for(int i=0;i<n;i++){
            sum+=costs[i][0];
            diff.push_back(costs[i][1]-costs[i][0]);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<n/2;i++){
            sum+=diff[i];
        }
        return sum;
    }
};