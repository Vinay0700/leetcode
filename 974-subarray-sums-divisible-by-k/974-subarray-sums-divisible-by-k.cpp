class Solution{
public:
   int subarraysDivByK(vector<int>&A, int K){
        vector<int>counts(K,0);
        int sum=0;
        for(int x : A){
            sum+= (x%K+K)%K;
            counts[sum % K]++;
       }
        int result=counts[0];
        for(int c: counts)
            result+=(c*(c-1))/2;
        return result;
}
   };