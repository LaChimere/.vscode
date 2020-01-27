#include <iostream>
#include <string>
using namespace std;

const int MAXNUM = 1000;

class bigNum {
    private:
        int d[MAXNUM];
        int len;
    public:
        bigNum() {
            for (int i = 0; i < MAXNUM; i++)
                d[i] = 0;
            len = 0;
        }
        bigNum(const string &s) {
            len = s.length();
            auto it = s.rbegin();
            for (int i = 0; it != s.rend() && i < MAXNUM; it++, i++)
                d[i] = *it - '0';
        }
        ~bigNum();
        const bigNum & operator= (const bigNum &x) {
            len = x.len;
            for (int i = 0; i < MAXNUM; i++)
                d[i] = x.d[i];
            return *this;
        }
        bigNum operator+ (const bigNum &x) const {
            bigNum result;
            int carry = 0;
            for (int i = 0; i < len || i < x.len; i++) {
                int temp = d[i] + x.d[i] + carry;
                result.d[result.len++] = temp % 10;
                carry = temp / 10;
            }
            if (carry != 0)
                result.d[result.len++] = carry;
            return result;
        }
        bigNum operator- (const bigNum &b) const {
            bigNum a;
            a.len = len;
            for (int i = 0; i < MAXNUM; i++)
                a.d[i] = d[i];
            bigNum result;
            for (int i = 0; i < a.len || i < b.len; i++) {
                if (a.d[i] < b.d[i]) {
                    a.d[i + 1]--;
                    a.d[i] += 10;
                }
                result.d[result.len++] = a.d[i] - b.d[i];
            }
            while (result.len > 1 && result.d[result.len - 1] == 0)
                result.len--;
            return result;
        }
        bigNum operator* (const int &x) const {
            bigNum result;
            int carry = 0;
            for (int i = 0; i < len; i++) {
                int temp = d[i] * x + carry;
                result.d[result.len++] = temp % 10;
                carry = temp / 10;
            }
            while (carry != 0) {
                result.d[result.len++] = carry % 10;
                carry /= 10;
            }
            return result;
        }
};