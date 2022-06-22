class StockSpanner {
public:
    stack<pair<int,int>> sk;
    StockSpanner() {    }
    
    int next(int price) {
	
        int ct = 1;
        while(sk.size() and sk.top().first <= price)    
				ct+=sk.top().second , sk.pop();    
				
        sk.push({price , ct});
        return ct;
    }
};