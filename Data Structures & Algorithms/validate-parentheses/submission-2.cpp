class Solution {
public:

    bool isValid(string s) {
        
    std::stack<char> check;
    std::unordered_map<char, char> valid = {
        {'{','}'},
        {'(',')'},
        {'[',']'}
    };
    for(char b : s) {

        if(b == '(' || b == '{' || b == '[') {
            check.push(b);
        }

        else if(!check.empty() && valid[check.top()] == b) check.pop();

        else return false;

            
    }
    return check.empty();
    }

};
