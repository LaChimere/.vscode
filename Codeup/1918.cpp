#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node {
    double num;
    char op;
    bool flag;  // flag == true: num, flag == false: oper.
};

stack<node> opers;
queue<node> expression;
stack<double> calNums;
map<char, int> op_priority;

void clearBlanks(string &s) {
    for (auto it = s.begin(); it != s.end(); it++)
        if (*it == ' ')
            s.erase(it);
}

void in_to_post(string &s) {
    clearBlanks(s);
    for (auto it = s.begin(); it != s.end();) {
        node temp;
        if (*it >= '0' && *it <= '9') {
            temp.num = *it - '0';
            it++;
            while (it != s.end() && *it >= '0' && *it <= '9') {
                temp.num = temp.num * 10.0 + (*it - '0');
                it++;
            }
            temp.flag = true;
            expression.push(temp);
        } else {
            temp.flag = false;
            while (!opers.empty() && op_priority[*it] <= op_priority[opers.top().op]) {
                expression.push(opers.top());
                opers.pop();
            }
            temp.op = *it;
            opers.push(temp);
            it++;
        }
    }
    while (!opers.empty()) {
        expression.push(opers.top());
        opers.pop();
    }
}

double getResult() {
    double temp1, temp2, temp;
    node front;
    while (!expression.empty()) {
        front = expression.front();
        expression.pop();
        if (front.flag == true)
            calNums.push(front.num);
        else {
            temp2 = calNums.top();
            calNums.pop();
            temp1 = calNums.top();
            calNums.pop();
            if (front.op == '+')
                temp = temp1 + temp2;
            else if (front.op == '-')
                temp = temp1 - temp2;
            else if (front.op == '*')
                temp = temp1 * temp2;
            else
                temp = temp1 / temp2;
            calNums.push(temp);
        }
    }
    return calNums.top();
}

int main() {
    op_priority['+'] = op_priority['-'] = 1;
    op_priority['*'] = op_priority['/'] = 2;
    string str;
    while (getline(cin, str), str != "0") {
        while (!calNums.empty())
            calNums.pop();
        in_to_post(str);
        printf("%.2f\n", getResult());
    }
    return 0;
}