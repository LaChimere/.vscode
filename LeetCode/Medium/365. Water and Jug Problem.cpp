#include "tools"
class Solution {
private:
    int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

    const int STATE_NUM = 6;
    pair<int, int> op(int type, const pair<int, int>& state, int x, int y) {
        switch (type) {
            case 0 : return make_pair(x, state.second);             // fill x jug
            case 1 : return make_pair(state.first, y);              // fill y jug
            case 2 : return make_pair(0, state.second);             // empty x jug
            case 3 : return make_pair(state.first, 0);              // empty y jug
            case 4 : {
                // move water from x to y till x is empty or y is full
                int move = min(state.first, y - state.second);
                return make_pair(state.first - move, state.second + move);
            }
            case 5 : {
                // move water from y to x till x is full or y is empty
                int move = min(x - state.first, state.second);
                return make_pair(state.first + move, state.second - move);
            }
        }
        return make_pair(0, 0);
    }

    struct HashPair {
        size_t operator()(const pair<int, int>& key) const noexcept {
            return size_t(key.first) * 100000007 + key.second;
        }
    };
public:
    bool canMeasureWater(int x, int y, int z) {
        // Bezout's identity
        if (x + y < z) return false;
        if (z == 0 || x == z || y == z || x + y == z) return true;
        return z % gcd(x, y) == 0;
    }

    bool canMeasureWaterBFS(int x, int y, int z) {
        unordered_set<pair<int, int>, HashPair> mark;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first + cur.second == z) return true;
            for (int i = 0; i < STATE_NUM; i++) {
                auto next = op(i, cur, x, y);
                if (mark.find(next) != mark.end()) continue;
                mark.insert(next);
                q.push(next);
            }
        }
        return false;
    }

    bool canMeasureWaterDFS(int x, int y, int z) {
        // using stack to avoid stack-overflowing
        stack<pair<int, int>> st;
        st.emplace(0, 0);
        auto hash_function = [](const pair<int, int>& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<pair<int, int>, decltype(hash_function)> seen(0, hash_function);
        while (!st.empty()) {
            if (seen.count(st.top())) {
                st.pop();
                continue;
            }
            seen.emplace(st.top());
            auto [remain_x, remain_y] = st.top();
            st.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) return true;
            st.emplace(x, remain_y);        // fill x jug
            st.emplace(remain_x, y);        // fill y jug
            st.emplace(0, remain_y);        // empty x jug
            st.emplace(remain_x, 0);        // empty y jug
            int move_x = min(remain_x, y - remain_y);
            int move_y = min(x - remain_x, remain_y);
            // move water from x to y till x is empty or y is full
            st.emplace(remain_x - move_x, remain_y + move_x);
            // move water from y to x till x is full or y is empty
            st.emplace(remain_x + move_y, remain_y - move_y);
        }
        return false;
    }
};