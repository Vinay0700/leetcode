class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        //calculate  next smaller to left and right
        //and count number of times a[i] is the min
        int n = a.size();
        vector<int> left(n,-1); //idx of smaller element tha  a[i] to left
        stack<int> s;
        for(int i=0;i<n;i++){
            int cur = a[i];
            while(!s.empty() && cur<= a[s.top()]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        vector<int> right(n,n);
        for(int i=n-1;i>=0;i--){
            int cur = a[i];
            while(!s.empty() && cur< a[s.top()]){
                //look carefully there's no equal sign here as we can count double occurrences twice
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }
        
        int ans =0 ;
        long mod = 1e9 +7;
        for(int i=0;i<n;i++){
            int cl = i- (left[i]+1)+1;
            int cr = (right[i]-1)-i + 1;
            ans = (ans + (long)a[i]*cl*cr)%mod;
            
        }
        return ans;
    }
};