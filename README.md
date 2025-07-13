# order-matching-engine-cpp
 Mini stock exchange simulator in C++ with limit order matching.

# 💹 C++ Order Matching Engine

A mini stock exchange simulator built using C++. Supports basic **limit order matching** between buy and sell orders using **price-time (FIFO) priority**.

---

# 📌 Features
- ✅ Buy/Sell limit order support
- ✅ Matches best price using price-time priority
- ✅ FIFO queue for orders at same price
- ✅ Written in clean, beginner-friendly C++ using STL



# 🧠 Data Structures Used
- `map<int, queue<Order>>` for order book
- `struct Order` to hold order details



# 🚀 How to Run

```bash
g++ -o orderbook order_matching_engine.cpp
./orderbook
