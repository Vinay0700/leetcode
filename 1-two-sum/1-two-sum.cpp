class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> answer;
       unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(m.find(diff)!=m.end() ){
                answer.push_back(i);
                answer.push_back(m.find(diff)->second);
                return answer;
            }
          
                m[nums[i]]=i;
            
            
        }
        return answer;
    }
};