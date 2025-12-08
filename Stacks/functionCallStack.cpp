#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isAlphaNumeric(char c) {
    return isAlpha(c) || (c >= '0' && c <= '9');
}

// Dynamic String class
class DynamicString {
private:
    char* data;
    int length;
    
public:
    DynamicString() : data(nullptr), length(0) {}
    
    DynamicString(const char* str) {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        } else {
            data = nullptr;
            length = 0;
        }
    }
    
    DynamicString(const DynamicString& other) {
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strcpy(data, other.data);
        } else {
            data = nullptr;
        }
    }
    
    ~DynamicString() {
        delete[] data;
    }
    
    DynamicString& operator=(const DynamicString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            if (other.data) {
                data = new char[length + 1];
                strcpy(data, other.data);
            } else {
                data = nullptr;
            }
        }
        return *this;
    }
    
    const char* c_str() const { return data ? data : ""; }
    int size() const { return length; }
    bool empty() const { return length == 0; }
    
    char& operator[](int index) { return data[index]; }
    char operator[](int index) const { return data[index]; }
    
    bool operator==(const DynamicString& other) const {
        if (length != other.length) return false;
        // Correct comparison when data is null (empty strings)
        if (!data && !other.data) return true;
        if (!data || !other.data) return false;
        return strcmp(data, other.data) == 0;
    }
};

// Dynamic Array template
template<typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int count;
    
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
public:
    DynamicArray(int initialCapacity = 10) : capacity(initialCapacity), count(0) {
        data = new T[capacity];
    }
    
    // Rule of Three components for DynamicArray
    DynamicArray(const DynamicArray& other) : capacity(other.capacity), count(other.count) {
        data = new T[capacity];
        for (int i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            count = other.count;
            data = new T[capacity];
            for (int i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    ~DynamicArray() {
        delete[] data;
    }
    
    void push_back(const T& value) {
        if (count >= capacity) {
            resize(capacity * 2);
        }
        data[count++] = value;
    }
    
    void pop_back() {
        if (count > 0) count--;
    }
    
    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }
    
    int size() const { return count; }
    bool empty() const { return count == 0; }
    
    void clear() { count = 0; }
    
    bool contains(const T& value) const {
        for (int i = 0; i < count; i++) {
            if (data[i] == value) return true;
        }
        return false;
    }
};

// Stack implementation - 8 marks
class Stack {
private:
    DynamicArray<DynamicString> data;
    int maxSize;
    
public:
    Stack(int capacity) : maxSize(capacity) {}
    
    void push(const DynamicString& value) {
        if (!isFull()) {
            data.push_back(value);
        }
    }
    
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }
    
    DynamicString top() const {
        if (!isEmpty()) {
            return data[data.size() - 1];
        }
        return DynamicString();
    }
    
    bool isEmpty() const { return data.empty(); }
    bool isFull() const { return data.size() >= maxSize; }
    int size() const { return data.size(); }
    
    void display() const {
        cout << "Call Stack: [";
        for (int i = 0; i < data.size(); i++) {
            cout << data[i].c_str();
            if (i < data.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};


class CircularPriorityQueue {
private:
    struct QueueItem {
        DynamicString funcName;
        int priority;
    };
    
    QueueItem* data;
    int capacity;
    int size;
    int front;
    
public:
    CircularPriorityQueue(int cap) : capacity(cap), size(0), front(0) {
        data = new QueueItem[capacity];
    }
    
    ~CircularPriorityQueue() {
        delete[] data;
    }
    
    bool isFull() const { return size == capacity; }
    bool isEmpty() const { return size == 0; }
    
    bool enqueue(const DynamicString& funcName, int priority) {
        if (isFull()) return false;
        
        int pos = (front + size) % capacity;
        data[pos].funcName = funcName;
        data[pos].priority = priority;
        size++;
        return true;
    }
    
    DynamicString dequeue() {
        if (isEmpty()) return DynamicString();
        
        // Find highest priority (lowest number) - maintain order for same priority
        int highestPriority = 6;
        int highestPriorityIndex = -1;
        
        // The index 'i' is the offset from the front
        for (int i = 0; i < size; i++) {
            int pos = (front + i) % capacity;
            if (data[pos].priority < highestPriority) {
                highestPriority = data[pos].priority;
                highestPriorityIndex = i;
            }
        }
        
        if (highestPriorityIndex == -1) return DynamicString();
        
        int targetPos = (front + highestPriorityIndex) % capacity;
        DynamicString result = data[targetPos].funcName;
        
        // Remove by shifting to maintain order
        for (int i = highestPriorityIndex; i < size - 1; i++) {
            int current = (front + i) % capacity;
            int next = (front + i + 1) % capacity;
            data[current] = data[next];
        }
        
        size--;
        return result;
    }
    
    void display() const {
        cout << "Ready Queue: [";
        for (int i = 0; i < size; i++) {
            int pos = (front + i) % capacity;
            cout << data[pos].funcName.c_str() << "(" << data[pos].priority << ")";
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Circular Queue implementation 
class CircularQueue {
private:
    DynamicString* data;
    int capacity;
    int size;
    int front;
    int rear;
    
public:
    CircularQueue(int cap) : capacity(cap), size(0), front(0), rear(-1) {
        data = new DynamicString[capacity];
    }
    
    ~CircularQueue() {
        delete[] data;
    }
    
    bool isFull() const { return size == capacity; }
    bool isEmpty() const { return size == 0; }
    
    bool enqueue(const DynamicString& funcName) {
        if (isFull()) return false;
        
        rear = (rear + 1) % capacity;
        data[rear] = funcName;
        size++;
        return true;
    }
    
    DynamicString dequeue() {
        if (isEmpty()) return DynamicString();
        
        DynamicString result = data[front];
        front = (front + 1) % capacity;
        size--;
        return result;
    }
    
    void display() const {
        cout << "Waiting Queue: [";
        for (int i = 0; i < size; i++) {
            int pos = (front + i) % capacity;
            cout << data[pos].c_str();
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Function class
class Function {
public:
    DynamicString name;
    int recursionCount;
    DynamicArray<DynamicString> nestedCalls;
    int priority;
    
    Function(const DynamicString& n, int rc, const DynamicArray<DynamicString>& nested, int p) 
        : name(n), recursionCount(rc), nestedCalls(nested), priority(p) {}
    
    Function() : recursionCount(1), priority(1) {}
};


class FunctionScheduler {
private:
    struct FunctionNode {
        DynamicString name;
        Function func;
        FunctionNode* next;
        
        FunctionNode(const DynamicString& n) : name(n), next(nullptr) {}
    };
    
    FunctionNode* functionTable;
    DynamicArray<DynamicString> topLevelCalls;
    Stack callStack;
    CircularPriorityQueue readyQueue;
    CircularQueue waitingQueue;
    int maxStackSize;
    
    Function* findFunction(const DynamicString& name) {
        FunctionNode* current = functionTable;
        while (current) {
            if (current->name == name) {
                return &current->func;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    bool functionExists(const DynamicString& name) {
        return findFunction(name) != nullptr;
    }
    
    void addFunctionNode(const DynamicString& name, const Function& func) {
        FunctionNode* newNode = new FunctionNode(name);
        newNode->func = func;
        
        if (!functionTable) {
            functionTable = newNode;
        } else {
            FunctionNode* current = functionTable;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    
    int evaluateExpression(const DynamicString& expr) {
        const char* str = expr.c_str();
        int result = 0;
        int currentNum = 0;
        char op = '+';
        bool hasOp = false;
        
        for (int i = 0; str[i] != '\0'; i++) {
            if (isdigit(str[i])) {
                currentNum = currentNum * 10 + (str[i] - '0');
            } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                if (!hasOp) {
                    result = currentNum;
                } else {
                    switch (op) {
                        case '+': result += currentNum; break;
                        case '-': result -= currentNum; break;
                        case '*': result *= currentNum; break;
                        case '/': 
                            if (currentNum == 0) throw "Division by zero";
                            result /= currentNum; 
                            break;
                    }
                }
                op = str[i];
                currentNum = 0;
                hasOp = true;
            } else if (!isspace(str[i])) {
                throw "Invalid character in expression";
            }
        }
        
        
        if (hasOp) {
            switch (op) {
                case '+': result += currentNum; break;
                case '-': result -= currentNum; break;
                case '*': result *= currentNum; break;
                case '/': 
                    if (currentNum == 0) throw "Division by zero";
                    result /= currentNum; 
                    break;
            }
        } else {
            result = currentNum;
        }
        
        if (result < 1) throw "Result less than 1";
        return result;
    }
    
    
    bool hasCircularDependency(const DynamicString& startFunc, DynamicArray<DynamicString>& visited, DynamicArray<DynamicString>& recStack) {
        // Check if already in current recursion path (cycle found)
        for (int i = 0; i < recStack.size(); i++) {
            if (recStack[i] == startFunc) return true;
        }
        
        // Check if already visited and non-cyclic in a previous path
        if (visited.contains(startFunc)) return false;
        
        // Mark as visited and add to current recursion path
        visited.push_back(startFunc);
        recStack.push_back(startFunc);
        
        Function* func = findFunction(startFunc);
        if (func) {
            for (int i = 0; i < func->nestedCalls.size(); i++) {
                if (hasCircularDependency(func->nestedCalls[i], visited, recStack)) {
                    return true;
                }
            }
        }
        
       
        if (!recStack.empty() && recStack[recStack.size() - 1] == startFunc) {
            recStack.pop_back(); 
        }

        return false;
    }
    
    bool checkCircularDependency() {
        DynamicArray<DynamicString> visited;
        DynamicArray<DynamicString> recStack;
        
        FunctionNode* current = functionTable;
        while (current) {
            recStack.clear(); 
            if (hasCircularDependency(current->name, visited, recStack)) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    
    void executeFunction(const DynamicString& funcName, int depth = 0) {
        if (callStack.isFull()) {
            cout << "Error: Stack overflow while calling " << funcName.c_str() << endl;
            return;
        }
        
        Function* func = findFunction(funcName);
        if (!func) {
            cout << "Error: Function " << funcName.c_str() << " not defined" << endl;
            return;
        }
        
        // Execute recursion
        for (int i = 0; i < func->recursionCount; i++) {
            if (callStack.isFull()) {
                cout << "Error: Stack overflow while calling " << funcName.c_str() << endl;
                break;
            }
            
            cout << funcName.c_str() << " called" << endl;
            callStack.push(funcName);
            callStack.display();
            
            // Execute nested calls
            for (int j = 0; j < func->nestedCalls.size(); j++) {
                executeFunction(func->nestedCalls[j], depth + 1);
            }
            
            if (!callStack.isEmpty() && callStack.top() == funcName) {
                callStack.pop();
                cout << funcName.c_str() << " finished" << endl;
                callStack.display();
            }
        }
    }
    
    
    bool isValidFunctionName(const DynamicString& name) {
        if (name.empty()) return false;
        
        const char* str = name.c_str();
        if (!isAlpha(str[0])) return false;
        
        for (int i = 1; str[i] != '\0'; i++) {
            if (!isAlphaNumeric(str[i])) return false;
        }
        return true;
    }
    
    bool validateParentheses(const char* input) {
        int count = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '(') count++;
            else if (input[i] == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
    
public:
    FunctionScheduler(int n, int m, int s, int r, int w) 
        : callStack(s), readyQueue(r), waitingQueue(w), maxStackSize(s), functionTable(nullptr) {}
    
    ~FunctionScheduler() {
        FunctionNode* current = functionTable;
        while (current) {
            FunctionNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    
    bool addFunction(const DynamicString& name, const DynamicString& recursionStr, 
                     const DynamicArray<DynamicString>& nested, int priority) {
       
        if (functionExists(name)) {
            cout << "Error: Duplicate function name " << name.c_str() << endl;
            return false;
        }
       
        if (!isValidFunctionName(name)) {
            cout << "Error: Invalid function name " << name.c_str() << endl;
            return false;
        }
        
        
        if (priority < 1 || priority > 5) {
            cout << "Error: Priority must be between 1-5 for " << name.c_str() << endl;
            return false;
        }
        
        int recursionCount = 1;
        
        if (!recursionStr.empty()) {
            try {
                recursionCount = evaluateExpression(recursionStr);
                if (recursionCount < 1) throw "Result less than 1";
            } catch (const char* e) {
               
                cout << "Error: Invalid recursion expression in " << name.c_str() << " - " << e << endl;
                return false;
            }
        }
        
        Function func(name, recursionCount, nested, priority);
        addFunctionNode(name, func);
        return true;
    }
    
    void addTopLevelCall(const DynamicString& funcName) {
        topLevelCalls.push_back(funcName);
    }
    
    void run() {
      
        if (checkCircularDependency()) {
            cout << "Error: Circular Dependency exists" << endl;
            return;
        }
        
        
        for (int i = 0; i < topLevelCalls.size(); i++) {
            Function* func = findFunction(topLevelCalls[i]);
            if (func) {
                if (readyQueue.enqueue(topLevelCalls[i], func->priority)) {
                    cout << topLevelCalls[i].c_str() << " added to Ready Queue" << endl; 
                    readyQueue.display(); 
                    waitingQueue.display();
                } else if (waitingQueue.enqueue(topLevelCalls[i])) {
                    cout << topLevelCalls[i].c_str() << " added to Waiting Queue" << endl;
                    readyQueue.display();
                    waitingQueue.display();
                } else {
                    cout << "Error: All queues full, cannot schedule " << topLevelCalls[i].c_str() << endl; 
                    readyQueue.display();
                    waitingQueue.display();
                }
            } else {
                cout << "Error: Function " << topLevelCalls[i].c_str() << " not defined" << endl;
            }
        }
        
        // Process the queues
        while (!readyQueue.isEmpty() || !waitingQueue.isEmpty()) {
            if (!readyQueue.isEmpty()) {
                DynamicString funcToExecute = readyQueue.dequeue();
                cout << "Dequeued " << funcToExecute.c_str() << " from ready queue for execution" << endl;
                readyQueue.display();
                waitingQueue.display();
                
                executeFunction(funcToExecute);
            }
            
           
            if (!waitingQueue.isEmpty() && !readyQueue.isFull()) {
                DynamicString movedFunc = waitingQueue.dequeue();
                Function* func = findFunction(movedFunc);
                if (func) {
                    if (readyQueue.enqueue(movedFunc, func->priority)) {
                        cout << movedFunc.c_str() << " moved from waiting queue to ready queue" << endl;
                        readyQueue.display();
                        waitingQueue.display();
                    }
                }
            }
        }
    }
};


bool parseFunctionSignature(const char* input, DynamicString& name, DynamicString& recursion) {
    const char* parenStart = strchr(input, '(');
    const char* parenEnd = strrchr(input, ')');
    
    
    if (!parenStart || !parenEnd || parenEnd <= parenStart) {
        cout << "Error: Invalid parentheses in function definition" << endl;
        return false;
    }
    
   
    int nameLen = parenStart - input;
    if (nameLen <= 0) {
        cout << "Error: Empty function name" << endl;
        return false;
    }
    
    char* nameStr = new char[nameLen + 1];
    strncpy(nameStr, input, nameLen);
    nameStr[nameLen] = '\0';
    name = DynamicString(nameStr);
    delete[] nameStr;
    
   
    int recurLen = parenEnd - parenStart - 1;
    if (recurLen > 0) {
        char* recurStr = new char[recurLen + 1];
        strncpy(recurStr, parenStart + 1, recurLen);
        recurStr[recurLen] = '\0';
        recursion = DynamicString(recurStr);
        delete[] recurStr;
    }
    
    return true;
}

DynamicArray<DynamicString> parseNestedCalls(const char* input) {
    DynamicArray<DynamicString> nested;
    
    if (!input || strlen(input) <= 2 || input[0] != '{' || input[strlen(input) - 1] != '}') {
        return nested;
    }
    
    // Extract content between braces
    int contentLen = strlen(input) - 2;
    // content + 1 for null terminator, not contentLen + 1
    char* content = new char[contentLen + 1]; 
    strncpy(content, input + 1, contentLen);
    content[contentLen] = '\0';
    
    
    // strtok modifies its first argument, so content is necessary
    char* token = strtok(content, ",");
    while (token) {
        // Remove whitespace
        char* cleaned = new char[strlen(token) + 1];
        int j = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (!isspace(token[i])) {
                cleaned[j++] = token[i];
            }
        }
        cleaned[j] = '\0';
        
        if (strlen(cleaned) > 0) {
            nested.push_back(DynamicString(cleaned));
        }
        delete[] cleaned;
        
        token = strtok(nullptr, ",");
    }
    
    delete[] content;
    return nested;
}

int main() {
    
    int N, M, S, R, W;
    
    
    if (!(cin >> N >> M >> S >> R >> W)) {
        cout << "Error: Invalid input format" << endl;
        return 1;
    }
    
   
    if (N < 1 || N > 50 || M < 1 || M > 50 || S < 1 || S > 50 || 
        R < 1 || R > 50 || W < 1 || W > 50) {
        cout << "Error: Constraints violation. All values must be between 1-50" << endl;
        return 1;
    }
    
    cin.ignore(); 
    
    FunctionScheduler scheduler(N, M, S, R, W);
    int validFunctions = 0;
    
    
    for (int i = 0; i < N; i++) {
        char line[256];
        cin.getline(line, 256);
        
       
        char* braceStart = strchr(line, '{');
        char* braceEnd = strchr(line, '}');
        char* priorityStart = strrchr(line, ' ');
        
        if (!braceStart || !braceEnd || !priorityStart) {
            cout << "Error: Invalid function definition format" << endl;
            continue;
        }
        
        // Extract parts
        int beforeBracesLen = braceStart - line;
        char* beforeBraces = new char[beforeBracesLen + 1];
        strncpy(beforeBraces, line, beforeBracesLen);
        beforeBraces[beforeBracesLen] = '\0';
        
        int nestedLen = braceEnd - braceStart + 1;
        char* nestedStr = new char[nestedLen + 1];
        strncpy(nestedStr, braceStart, nestedLen);
        nestedStr[nestedLen] = '\0';
        
        int priority = atoi(priorityStart + 1);
        
        // Parse function signature
        DynamicString name, recursion;
        if (parseFunctionSignature(beforeBraces, name, recursion)) {
            
            DynamicArray<DynamicString> nested = parseNestedCalls(nestedStr);
            
            if (scheduler.addFunction(name, recursion, nested, priority)) {
                validFunctions++;
            }
        }
        
        delete[] beforeBraces;
        delete[] nestedStr;
    }
    
    if (validFunctions == 0) {
        cout << "Error: No valid functions defined" << endl;
        return 1;
    }
    
    
    for (int i = 0; i < M; i++) {
        char call[100];
        cin.getline(call, 100);
        scheduler.addTopLevelCall(DynamicString(call));
    }
    
    
    scheduler.run();
    
    return 0;
}