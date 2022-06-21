class Solution {
 
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // use monotonic stack since it is a next greater element problem 
        
        stack<pair<int,int> > s;
        vector<int> ans(T.size());
        // populate stack 
        for(int i = T.size()-1;i>=0; i--)
        {
            auto curr = T[i];
            // top element of the stack should be the largest 
            while(!s.empty() && curr >= s.top().first)
            {
                s.pop();
            }
            
            ans[i] = s.empty() ? 0: s.top().second - i; 
            s.push(pair<int, int>(T[i], i));
        }
        // T: O(n)
        // S: O(n)
        return ans;
    }
};