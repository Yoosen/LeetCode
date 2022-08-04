// 3.公司食堂

// 只能通过 2/3 ，需要完善，可能需要二分查找

#include <bits/stdc++.h>

using namespace std;

// 男性
void mSolve(vector<int> &v) {
    int pos = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            pos = i + 1;
            break;
        }
    }

    // 没有 1的位置，找 0
    if (pos == 0) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 0) {
                pos = i + 1;
                break;
            }
        }
    }
    v[pos - 1]++;

    cout << pos << endl;
}

void fSolve(vector<int> &v) {
    int pos = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            pos = i + 1;
            break;
        }
    }

    // 没有 0 的位置，找 1
    if (pos == 0) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 1) {
                pos = i + 1;
                break;
            }
        }
    }
    v[pos - 1]++;

    cout << pos << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        vector<int> v;

        string s1;
        cin >> n >> s1;

        for (int i = 0; i < n; ++i) {
            v.push_back(s1[i] - '0');
        }

        int M;
        string  s2;
        cin >> M >> s2;

        for (int i = 0; i < M; ++i) {

            switch (s2[i]) {
                case 'M':
                    mSolve(v);
                    break;
                case 'F':
                    fSolve(v);
                    break;
                default:;
            }
        }

    }

    return 0;
}