class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(_stack.empty()) {
            _stack.push(0);
            min = val;
        }
        else {
            _stack.push(val - min);
            if(val < min) min = val;
        }

    }
    
    void pop() {
        
        if(_stack.empty()) return;

        long temp = _stack.top();
        _stack.pop();

        if(temp < 0) min = min - temp;
        
    }
    
    int top() {
        long temp = _stack.top();

        return (temp > 0 ) ? (temp + min) : min;
    }
    
    int getMin() {

        return  min;
    }

private:
    stack<long> _stack;
    long min;
};
