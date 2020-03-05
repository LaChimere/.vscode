#include "tools"

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // BFS
        unordered_map<int, Employee*> hash;
        queue<Employee*> q;
        Employee* em = nullptr;
        for (Employee* it : employees) {
            if (it->id != id)
                hash[it->id] = it;
            else em = it;
        }
        int sum = 0;
        q.push(em);
        while (!q.empty()) {
            Employee* cur = q.front();
            q.pop();
            sum += cur->importance;
            for (int subordinate : cur->subordinates)
                q.push(hash[subordinate]);
        }
        return sum;

        // DFS
        // Employee *root = nullptr;
        // for (Employee* it : employees) {
        //     if (it->id == id) {
        //         root = it;
        //         break;
        //     }
        // }
        // int sum = root->importance;
        // for (int subordinate : root->subordinates)
        //     sum += getImportance(employees, subordinate);
        // return sum;
    }
};