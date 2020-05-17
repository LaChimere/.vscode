#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, inDegree(numCourses, 0);
        vector<vector<int>> edge(numCourses);
        
        int check = 0;
        for (const auto& p : prerequisites) {
            inDegree[p[0]]++;
            check++;
            edge[p[1]].push_back(p[0]);
        }
        
        queue<int> vertex;
        for (int v = 0; v < numCourses; v++)
            if (!inDegree[v])
                vertex.push(v);
        
        while (!vertex.empty()) {
            int v = vertex.front();
            vertex.pop();
            res.push_back(v);
            
            for (int u : edge[v]) {
                inDegree[u]--;
                check--;
                if (!inDegree[u])
                    vertex.push(u);
            }
        }
        
        return check == 0 ? res : vector<int>({});
    }
};