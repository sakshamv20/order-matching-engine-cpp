#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// Structure to store each order
struct Order {
    int id;           // Unique Order ID
    string type;      // "buy" or "sell"
    int price;        // Limit price
    int quantity;     // Quantity of the order
};

// Global Order Book
map<int, queue<Order>> buyOrders;    // Buy orders: Highest price gets priority (reverse map)
map<int, queue<Order>> sellOrders;   // Sell orders: Lowest price gets priority
int orderId = 1; // Auto-incrementing order ID

//  Function to match buy and sell orders
void matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto highestBuy = --buyOrders.end();   // Buy orders sorted ascending → last = highest price
        auto lowestSell = sellOrders.begin();  // Sell orders sorted ascending → first = lowest price

        if (highestBuy->first >= lowestSell->first) {
            Order& buyOrder = highestBuy->second.front();
            Order& sellOrder = lowestSell->second.front();

            // Match quantity
            int tradedQty = min(buyOrder.quantity, sellOrder.quantity);

            // Show matched result
            cout << " Matched: Buy ID " << buyOrder.id
                 << " with Sell ID " << sellOrder.id
                 << " | Price: " << sellOrder.price
                 << " | Quantity: " << tradedQty << endl;

            // Reduce quantity
            buyOrder.quantity -= tradedQty;
            sellOrder.quantity -= tradedQty;

            // Remove fully filled orders from queue
            if (buyOrder.quantity == 0)
                highestBuy->second.pop();
            if (sellOrder.quantity == 0)
                lowestSell->second.pop();

            // If price queue empty, remove price level
            if (highestBuy->second.empty())
                buyOrders.erase(highestBuy);
            if (lowestSell->second.empty())
                sellOrders.erase(lowestSell);
        } else {
            // No more match possible
            break;
        }
    }
}

//  Function to add a new order
void addOrder(const string& type, int price, int quantity) {
    Order newOrder = {orderId++, type, price, quantity};

    if (type == "buy") {
        buyOrders[price].push(newOrder);
    } else if (type == "sell") {
        sellOrders[price].push(newOrder);
    } else {
        cout << "❌ Invalid order type. Use 'buy' or 'sell'.\n";
        return;
    }

    // Try to match after adding
    matchOrders();
}

//  Main function with CLI
int main() {
    cout << "Welcome to the C++ Order Matching Engine\n"<<endl;
    cout << "Enter orders in format: buy/sell price quantity\n"<<endl;;
    cout << "Type 'exit' to quit.\n"<<endl;

    while (true) {
        cout << "\n Order> ";
        string type;
        int price, quantity;
        cin >> type;

        if (type == "exit") break;

        cin >> price >> quantity;
        addOrder(type, price, quantity);
    }

    cout << "\n Exiting Order Matching Engine. Thank you!\n";
    return 0;
}
