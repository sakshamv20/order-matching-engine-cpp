# 💹 C++ Order Matching Engine

A mini stock exchange simulator built using C++.  
This project simulates basic **limit order matching** between buy and sell orders using **price-time (FIFO) priority**, similar to how real-world exchanges operate.

---

## 📌 Features

- ✅ Supports Buy and Sell limit orders
- ✅ Matches orders using price-time (FIFO) priority
- ✅ Maintains separate order books for buy and sell sides
- ✅ Uses STL (`map`, `queue`) for efficient and clean implementation
- ✅ Fully command-line based and beginner-friendly

---

## 🧠 Data Structures Used

- `map<int, queue<Order>>` – to store buy/sell orders sorted by price  
- `struct Order` – to store order details like ID, type, price, and quantity

---

## 🚀 How to Run

Make sure you have a C++ compiler installed (like g++).

```
g++ -o orderbook order_matching_engine.cpp
./orderbook
```

## 🧪 Sample Input

buy 100 10
sell 95 5
sell 100 5
exit

## 📤 Sample Output

✅ Matched: Buy ID 1 with Sell ID 2 | Price: 95 | Quantity: 5
✅ Matched: Buy ID 1 with Sell ID 3 | Price: 100 | Quantity: 5

## 🎯 Concepts Covered
C++ Structs and STL Containers (map, queue)

FIFO logic for time-based priority

Price-time priority matching

Console input/output handling

Simulating real-world trading engine behavior

👨‍💻 Author
Made with ❤️ by Saksham Verma
Feel free to ⭐ star this repo if you found it helpful!
