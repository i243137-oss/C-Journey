#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

struct Item {
    string name;
    string barcode;
    int quantity;
    int price;
    int productId;
    static int nextId; 
    
    Item() : name(""), barcode(""), quantity(0), price(0), productId(0) {}
    
    void changeItemName(string name) {
        this->name = name;
    }
    
    void changeItemPrice(int price) {
        this->price = price;
    }
    
    void addQuantity(int quantity) {
        this->quantity += quantity;
    }
    
    void genBarcode() {
        srand(time(0));
        barcode = ""; 
        
        for(int i = 0; i < 2; i++) {
            int alphabet = rand() % (90 - 65 + 1) + 65;
            barcode += (char)alphabet;
        }
        
        for(int i = 0; i < 4; i++) {
            int num = rand() % (57 - 48 + 1) + 48;
            barcode += (char)num;
        }
    }
    
    void printItemsDetail() {
        cout << "Name: " << name << endl;
        cout << "Barcode: " << barcode << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Product ID: " << productId << endl;
    }
    
    friend istream & operator>>(istream & in, Item & item);
};

int Item::nextId = 0; 

struct Inventory {
    Item* items;
    int itemsNo;
    
    Inventory() : items(nullptr), itemsNo(0) {} 
    
    ~Inventory() { 
        delete[] items;
    }
    
    void addItem(Item* item = nullptr) {
        if(item != nullptr) {
            item->quantity += 1;
            cout << "Item added successfully" << endl;
        } else {
            Item newItem;
            cin >> newItem;
            
            Item* newItems = new Item[itemsNo + 1];
            
            for(int i = 0; i < itemsNo; i++) {
                newItems[i] = items[i];
            }
            
            newItems[itemsNo] = newItem;
            
            delete[] items;
            items = newItems;
            itemsNo++;
            
            cout << newItem.name<<" item added successfully" << endl;
        }
    }
    
    void removeItem(int id){
        if (id < 0 || id >= itemsNo) {
            cout << "Invalid item ID" << endl;
            return;
        }
        Item temp=items[id];
        Item* newItems=new Item[itemsNo-1];
        int j=0;
        for(int i=0; i<itemsNo;i++){
            if(i!=id){
                newItems[j++]=items[i];
            }
        }
        delete [] items;
        items=newItems;
        itemsNo--;
        cout << temp.name<<" item deleted successfully" << endl;
    }
    
    void printInventory() {
        if(itemsNo == 0) {
            cout << "Inventory is empty" << endl;
            return;
        }
        
        for(int i = 0; i < itemsNo; i++) {
            cout << "Item " << i + 1 << ":" << endl;
            items[i].printItemsDetail();
            cout << "-------------------" << endl;
        }
    }
};
 
istream & operator>>(istream & in, Item & item) {
    cout << "Item Name: ";
    in.ignore();
    getline(in, item.name);
   
    item.genBarcode();
    
    cout << "Item Price: ";
    in >> item.price;
    
    cout << "Item Quantity: ";
    in >> item.quantity;
    
    item.productId = Item::nextId++;
    
    cout << endl;
    return in;
}

struct Order {
    Item *items;
    int totalItems;
    int *quantities;
    int basePrice;
    int tax;
    int totalPrice;
    bool payMethod;
    bool status;
    static int nextId;
    int orderId;
    
    Order() : items(nullptr), totalItems(0), quantities(nullptr), 
              basePrice(0), tax(0), totalPrice(0), 
              payMethod(false), status(false) {
        orderId = nextId++;
    }
    
    ~Order() {
        delete[] items;
        delete[] quantities;
    }
    
    void addItemInOrder(Item item, int quantity = 1) {
        for(int i = 0; i < totalItems; i++) {
            if(item.productId == items[i].productId) {
                quantities[i] += quantity;
                cout << quantity << " more of " << item.name << " added to order" << endl;
                calculateBill();
                return;
            }
        }
        
        Item* newItems = new Item[totalItems + 1];
        int* newQuantities = new int[totalItems + 1];
        
        for(int i = 0; i < totalItems; i++) {
            newItems[i] = items[i];
            newQuantities[i] = quantities[i];
        }
        
        newItems[totalItems] = item;
        newQuantities[totalItems] = quantity;
        
        delete[] items;
        delete[] quantities;
        items = newItems;
        quantities = newQuantities;
        totalItems++;
        
        cout << quantity << " of " << item.name << " added to order successfully" << endl;
        calculateBill();
    }
    
    void removeItemFromOrder(int productId, int quantity = 1) {
        for(int i = 0; i < totalItems; i++) {
            if(items[i].productId == productId) {
                if(quantities[i] <= quantity) {
                    cout << "Removing all " << quantities[i] << " of " << items[i].name << " from order" << endl;
                    
                    Item* newItems = new Item[totalItems - 1];
                    int* newQuantities = new int[totalItems - 1];
                    
                    for(int j = 0, k = 0; j < totalItems; j++) {
                        if(j != i) {
                            newItems[k] = items[j];
                            newQuantities[k] = quantities[j];
                            k++;
                        }
                    }
                    
                    delete[] items;
                    delete[] quantities;
                    items = newItems;
                    quantities = newQuantities;
                    totalItems--;
                } else {
                    quantities[i] -= quantity;
                    cout << quantity << " of " << items[i].name << " removed from order" << endl;
                }
                
                calculateBill();
                return;
            }
        }
        
        cout << "Item with ID " << productId << " not found in order" << endl;
    }
    
    void calculateBill() {
        basePrice = 0;
        for(int i = 0; i < totalItems; i++) {
            basePrice += items[i].price * quantities[i];
        }
        
        if(payMethod) {
            tax = basePrice * 0.05;
        } else {
            tax = basePrice * 0.15;
        }
        
        totalPrice = basePrice + tax;
    }
    
    void printOrderDetails() {
        cout << "\n===== ORDER DETAILS =====" << endl;
        cout << "Order ID: " << orderId << endl;
        cout << "Status: " << (status ? "Completed" : "Pending") << endl;
        cout << "Payment Method: " << (payMethod ? "Card" : "Cash") << endl;
        cout << "Items in order:" << endl;
        cout << "----------------------------------------" << endl;
        
        for(int i = 0; i < totalItems; i++) {
            cout << setw(2) << quantities[i] << " x " 
                 << setw(15) << left << items[i].name 
                 << "PKR" << setw(5) << right << items[i].price 
                 << " = PKR" << setw(6) << items[i].price * quantities[i] << endl;
        }
        
        cout << "----------------------------------------" << endl;
        cout << setw(25) << left << "Base Price:" << "/-" << setw(7) << right << basePrice << endl;
        cout << setw(25) << left << "Tax:" << "/-" << setw(7) << right << tax << endl;
        cout << setw(25) << left << "Total Price:" << "/-" << setw(7) << right << totalPrice << endl;
        cout << "========================================\n" << endl;
    }
    
    void setPaymentMethod(bool method) {
        payMethod = method;
        calculateBill();
        cout << "Payment method set to: " << (payMethod ? "Card" : "Cash") << endl;
    }
    
    void completeOrder() {
        status = true;
        cout << "Order completed successfully!" << endl;
        printOrderDetails();
    }
};
int Order::nextId = 1; 

struct Node{
    Order* order;
    Node *next;
    Node(Order * ord){
        order = ord;
        next = nullptr;
    }
};

struct OrderHistory{
    Node *head;
    Node *tail;
    OrderHistory(){
        head = nullptr;
        tail = nullptr;
    }
    
    void addOrder(Order *ord) {
        Node* newNode = new Node(ord);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Order added to history successfully" << endl;
    }
    
    void removeOrder(int id) {
        if (head == nullptr) return;
        
        Node* current = head;
        Node* prev = nullptr;
        
        while (current != nullptr) {
            if (current->order->orderId == id) {
                if (prev == nullptr) {
                    head = current->next;
                    if (head == nullptr) tail = nullptr;
                } else {
                    prev->next = current->next;
                    if (current->next == nullptr) tail = prev;
                }
                delete current->order;
                delete current;
                cout << "Order removed from history" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Order not found " << endl;
    }
    
    void printOrdersHistory() {
        if (head == nullptr) {
            cout << "No orders in history" << endl;
            return;
        }
        
        Node* current = head;
        int orderCount = 1;
        
        cout << "\n===== ORDERS HISTORY =====" << endl;
        while (current != nullptr) {
            cout << "Order #" << orderCount++ << ":" << endl;
            current->order->printOrderDetails();
            current = current->next;
        }
        cout << "==========================" << endl;
    }
};

struct Store{
    Inventory stock;
    OrderHistory *pendingOrders;
    int totalRevenue;
    int pendingOrdersNo;
    OrderHistory history;
    
    Store(){
        pendingOrders = nullptr;
        totalRevenue = 0;
        pendingOrdersNo = 0;
        
        cout << "Add 3 items in Inventory " << endl;
        for(int i = 0; i < 3; i++){
            cout << "Enter Item " << i + 1 << endl;
            stock.addItem();
        }
    }
    
    void addOrder(){
        Order temp;
        stock.printInventory();
        
        while(true){
            cout << "Please Select (1-3)" << endl;
            cout << "1. Add item" << endl;
            cout << "2. Remove item " << endl;
            cout << "3. Proceed to pay" << endl;
            
            int choice;
            do {
                cin >> choice;
            } while(choice < 1 || choice > 3);
            
            if(choice == 1){
                cout << "Please Select Item (1-" << stock.itemsNo << ")" << endl;
                int n;
                do {
                    cin >> n;
                } while(n < 1 || n > stock.itemsNo);
                
                cout << "Enter Quantity (1-" << stock.items[n-1].quantity << ")" << endl;
                int q;
                do {
                    cin >> q;
                } while(q < 1 || q > stock.items[n-1].quantity);
                
                temp.addItemInOrder(stock.items[n-1], q);
            }
            
            if(choice == 2){
                cout << "Enter Product Id" << endl;
                int id;
                cin >> id;
                cout << "Enter quantity" << endl;
                int quan;
                cin >> quan;
                temp.removeItemFromOrder(id, quan);
            }
            
            if(choice == 3) break;
        }
        
        cout << "Please Select payment method " << endl;
        cout << "1. Cash" << endl;
        cout << "2. Credit Card" << endl;
        
        int p;
        do {
            cin >> p;
        } while(p < 1 || p > 2);
        
        temp.setPaymentMethod(p - 1);
        
        cout << "Proceed to checkout ?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. See Later" << endl;
        
        int c;
        do {
            cin >> c;
        } while(c < 1 || c > 2);
        
        if(c == 1){
            temp.status = true;
            temp.completeOrder();
            totalRevenue += temp.totalPrice;
            
            Order* completedOrder = new Order(temp);
            history.addOrder(completedOrder);
        } else {
            temp.status = false;
            pendingOrders->addOrder(&temp);
            pendingOrdersNo++;
        }
    }
    void showPendingOrders(){
    	pendingOrders->printOrdersHistory();
	}
	void removePendingOrder(int id ){
		pendingOrders->removeOrder(id);
	}
};
void displayMainMenu() {
    cout << "===== STORE MANAGEMENT SYSTEM =====" << endl;
    cout << "1. Inventory " << endl;
    cout << "2. Order " << endl;
    cout << "3. View Order History" << endl;
    cout << "4. View Pending Orders" << endl;
    cout << "5. View Revenue" << endl;
    cout << "6. Exit" << endl;
    cout << "===================================" << endl;
    cout << "Please enter your choice (1-6): ";
}

void displayInventoryMenu() {
    cout << endl << "===== INVENTORY MANAGEMENT =====" << endl;
    cout << "1. View All Items" << endl;
    cout << "2. Add New Item" << endl;
    cout << "3. Remove Item" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "================================" << endl;
    cout << "Please enter your choice (1-4): ";
}

void displayOrderMenu() {
    cout << endl << "===== ORDER  =====" << endl;
    cout << "1. Create New Order" << endl;
    cout << "2. View Pending Orders" << endl;
    cout << "3. Complete Pending Order" << endl;
    cout << "4. Remove Pending Order" << endl;
    cout << "5. Back to Main Menu" << endl;
    cout << "============================ "<< endl;
    cout << "Please enter your choice (1-5): ";
}

int main() {
    Store store;
    int mainChoice, subChoice, id;
    bool exitProgram = false;
    
    while (!exitProgram) {
        displayMainMenu();
        cin >> mainChoice;
        
        switch (mainChoice) {
            case 1:
                do {
                    displayInventoryMenu();
                    cin >> subChoice;
                    
                    switch (subChoice) {
                        case 1:
                            store.stock.printInventory();
                            break;
                        case 2:
                            store.stock.addItem();
                            break;
                        case 3:
                            cout << "Enter item ID to remove: ";
                            cin >> id;
                            store.stock.removeItem(id);
                            break;
                        case 4:
                            cout << "Going to Back" << endl;
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                } while (subChoice != 4);
                break;
                
            case 2:
                do {
                    displayOrderMenu();
                    cin >> subChoice;
                    
                    switch (subChoice) {
                        case 1:
                            store.addOrder();
                            break;
                        case 2:
                            store.showPendingOrders();
                            break;
                        case 3:
                            cout << "Enter order ID to complete: ";
                            cin >> id;
                            break;
                        case 4:
                            cout << "Enter order ID to remove: ";
                            cin >> id;
                            store.removePendingOrder(id);
                            break;
                        case 5:
                            cout << "Going to Back" << endl;
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                    }
                } while (subChoice != 5);
                break;
                
            case 3:
                store.history.printOrdersHistory();
                break;
                
            case 4:
                store.showPendingOrders();
                break;
                
            case 5:
                cout << "Total Revenue: " << store.totalRevenue << endl;
                break;
                
            case 6:
                exitProgram = true;
                cout << "Thank you" << endl;
                break;
                
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}