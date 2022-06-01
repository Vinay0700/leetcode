class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        
        nums.assign(s.begin(),s.end());
        int n = nums.size();
        return n;}
};