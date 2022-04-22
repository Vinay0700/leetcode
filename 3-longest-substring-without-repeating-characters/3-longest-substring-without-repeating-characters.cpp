class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r = n-1;
        
        unordered_set<char> visited;
        
        int maxStr = 0;

        for(int r=0;r<n;r++)
        {
            if(visited.find(s[r])==visited.end())
            {
                visited.insert(s[r]);
                maxStr = max(maxStr,r-l+1);
                
            }
            else
            {
                while(l!=r && s[l]!=s[r])
                    visited.erase(s[l++]);
                
                //Removing and adding the same element
                visited.erase(s[l++]);
                visited.insert(s[r]);
                
                maxStr = max(maxStr,r-l+1);
            }
        }
        
        return maxStr;
    }
};