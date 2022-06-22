class StockSpanner {
public:
    stack<int> stk;
    vector<int> vec;
    int i=0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        vec.push_back(price);
        int res;
        while(!stk.empty() && price>=vec[stk.top()]) stk.pop();
        
        res = stk.empty() ? (i+1) : (i-stk.top());
      
        stk.push(i++);
        return res;
    }
};