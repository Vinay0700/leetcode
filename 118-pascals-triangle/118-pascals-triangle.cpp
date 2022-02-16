class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       
        vector<int> b;
    vector<vector<int> > a;
    for (int line = 1; line <= numRows; line++)
    {
        int C = 1; 
        for (int i = 1; i <= line; i++) 
        {
            b.push_back(C);
            C = C * (line - i) / i; 
        }
        a.push_back(b);
        b.clear();        
}
        return a;
        
    }
};