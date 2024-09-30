class CustomStack {
public:
    int top;
    int sz;
    vector<int> stk;
    
    CustomStack(int maxSize) {
        sz = maxSize;
        top = -1;
        stk = vector<int>(maxSize);
    }
    
    void push(int x) {
        if (top < sz - 1) {
            stk[++top] = x;
        }
    }
    
    int pop() {
        if (top == -1) return -1;
        return stk[top--];
    }
    
    void increment(int k, int val) {
        int limit = min(k, top + 1);
        for (int i = 0; i < limit; ++i) {
            stk[i] += val;
        }
    }
};
