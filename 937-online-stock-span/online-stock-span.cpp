class StockSpanner {
public:
    stack <int> s;
    vector <int> prices;
    int i = 0; 

    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);

        while(!s.empty() && price >= prices[s.top()]) {
            s.pop();
        }

        int span;

        if(s.empty()) {
            span = i+1;
        }
        else {
            int prevHigh = s.top();
            span = i-prevHigh;
        }

        s.push(i);
        i++;

        return span;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */