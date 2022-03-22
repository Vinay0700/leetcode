class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int total_sum= INT_MIN;
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum=curr_sum+nums[i];
            total_sum=max(curr_sum,total_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return total_sum;
    }
};