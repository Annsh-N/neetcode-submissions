class MinStack {
public:
    vector<int> stck;
    vector<int> mins;

    MinStack() {
        stck = {};
        mins = {};
    }
    
    void push(int val) {
        stck.push_back(val);
        if (mins.empty() || val <= mins.back()) {
            mins.push_back(val);
        }
    }
    
    void pop() {
        if (stck.back() == mins.back()) {
            mins.pop_back();
        }
        stck.pop_back();

    }
    
    int top() {
        return stck.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
