class StockPrice {
 private:
  map<int, int> timestampToPrice;
  multiset<int> prices;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestampToPrice.count(timestamp)) {
      const int prevPrice = timestampToPrice[timestamp];
      prices.erase(prices.equal_range(prevPrice).first);
    }
    timestampToPrice[timestamp] = price;
    prices.insert(price);
    }
    
    int current() {
        return rbegin(timestampToPrice)->second;
    }
    
    int maximum() {
        return *rbegin(prices);
    }
    
    int minimum() {
        return *begin(prices);
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
