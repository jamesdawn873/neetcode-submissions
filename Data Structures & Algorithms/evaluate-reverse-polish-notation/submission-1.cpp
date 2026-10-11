class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> polish;
        for (string c: tokens){
            if (c  == "+" || c == "-" || c == "*" || c == "/"){
                int oper_i = polish.top();
                polish.pop();
                int oper_j = polish.top();
                polish.pop();
                switch (c[0]){
                    case '+':
                        polish.push(oper_i + oper_j);
                        break;
                    case '-':
                        polish.push(oper_j - oper_i);
                        break;
                    case '*':
                        polish.push(oper_i * oper_j);
                        break;
                    case '/':
                        polish.push(oper_j / oper_i);
                        break;
                }
            } else {
                polish.push(stoi(c));
            }
        }
        return polish.top();
    }
};
