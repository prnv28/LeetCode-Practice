#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << __builtin_popcount(N) << "\n";
    }
    return 0;
}