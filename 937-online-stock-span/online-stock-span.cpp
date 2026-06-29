class StockSpanner {
public:
    stack<pair<int,int>>st;
    int index;
    //prev greater element
    StockSpanner() {
        index=0;
        st.push({-1,-1});
    }
    
    int next(int price) {
        while(st.top().first!=-1 && st.top().first<=price){
            st.pop();
        }
        int pge = index - st.top().second ;
        st.push({price,index});
        index++;
        return pge;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */