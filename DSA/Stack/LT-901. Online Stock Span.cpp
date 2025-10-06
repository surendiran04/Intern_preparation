class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {  //until pge
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
class StockSpanner { //Brute Force
public:
    vector<int> stock;
    StockSpanner() {
        
    }
    int next(int price) {
        int count=1;
        int n=stock.size();
        int i=n-1;
        while(i>=0 && stock[i]<=price){
            count++;
            i--;
        }
        stock.push_back(price);
        return count;
    }
};
