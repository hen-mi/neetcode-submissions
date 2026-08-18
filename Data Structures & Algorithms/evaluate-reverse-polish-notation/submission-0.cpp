class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;

        for(const auto& t : tokens) {


                if(t == "+") {
                     int temp = values.top();
                    values.pop();
                    values.top() = values.top() + temp;
               
                }



                else if(t ==  "-") {
                    int temp = values.top();
                    values.pop();
                    values.top() = values.top() - temp;
                    

                }


                else if(t ==  "*") {
                     int temp = values.top();
                    values.pop();
                    values.top() = values.top() * temp;                   
                }

                else if(t == "/") {
                    int temp = values.top();
                    values.pop();
                    values.top() = values.top() / temp;

                } 

                else values.push(stoi(t));
                
        }

        return values.top();
    }
};
