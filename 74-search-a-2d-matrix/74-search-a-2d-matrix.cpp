class Solution {
public:
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ((matrix.size() == 0) || (matrix[0].size() == 0)) return false;
        int m=matrix.size();
        int n =matrix[0].size();
        int low=0,high=n-1,i=0;
        while(low<=high && i<m){
            if(matrix[i][n-1]<target) {i++;continue;}
            int mid=low+(high-low)/2;
            if(matrix[i][mid]==target) return true;
            else if(matrix[i][mid]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    
}};