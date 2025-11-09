#include <bits/stdc++.h>
using namespace std;

int n, ans;
string a[15], hv[15];
bool vs[15];

void Try(int i, int cou) {
    if (i > n) {
        ans = min(ans, cou);
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (!vs[j]) {
            vs[j] = true;
            hv[i] = a[j];

            // Nhánh cận
            int dd[127] = {};// Mảng đếm tần suất ký tự ASCII (đủ cho chữ cái 'A'–'Z').
            for (char c : hv[i]) dd[c]++; //Cộng 1 cho từng ký tự xuất hiện trong chuỗi hiện tại.
            for (char c : hv[i - 1]) dd[c]++;//Cộng 1 cho từng ký tự xuất hiện trong chuỗi trước đó.
            int dem = 0;
            for (int i = 'A'; i <= 'Z'; ++i) {
                if (dd[i] == 2) dem++; 
            //Nếu một ký tự có giá trị 2 → tức là xuất hiện trong cả hai chuỗi (mỗi chuỗi 1 lần). Mỗi ký tự trùng nhau như vậy được tính là 1 chi phí.
            }
            if (cou + dem < ans)
                Try(i + 1, cou + dem);

            vs[j] = false;
        }
    }
}

void testCase() {
    ans = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    Try(1, 0);
    cout << ans;
}

int main() {
    int T = 1;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}
