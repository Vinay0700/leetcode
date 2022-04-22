class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
       int length = s.size();
       int left =0,right =0;
        int answer=0;
        while(right < length){
            if(mpp[s[right]] != -1) left= max(mpp[s[right]]+1,left);
            mpp[s[right]]=right;
            answer=max(answer,right-left+1);
            right++;
        }
        return answer;}
        
};