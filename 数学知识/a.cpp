#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int a[N], ta[N];

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> ta[i];
        }

        vector<int> stack;
        int j = 0;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            stack.push_back(a[i]);
            while (!stack.empty() && stack.back() == ta[j]) {
                stack.pop_back();
                j++;
            }
        }

        if (!stack.empty()) {
            valid = false;
        }

        if (valid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
