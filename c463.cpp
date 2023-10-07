#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_len(vector<vector<int>>& f, int r, int& count) { //計算所有節點高度
    if (f[r][0] == 0) {
        return 0;
    }
    int m1 = -1, l;
    l = f[r][0];
    for (int j = 1; j <= l; j++) {
        int len = find_len(f, f[r][j], count) + 1; //計算節點
        m1 = max(m1, len);
    }
    count += m1; 
    return m1;
}

int main() {
    int n, a, r, h, count = 0;
    cin >> n;
    vector<int> as(n + 1, 0);
    vector<vector<int>> f(n + 1, vector<int>(n, 0));
    for (int i = 1; i <= n; i++) {  //輸入
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> f[i][j];
            as[f[i][j]] = 1;
        }
        f[i][0] = a; //子節點個數放在第0個
    }
    for (int i = 0; i < n; i++) {  //找root
        if (as[i] != 1) {
            r = i;
        }
    }
    cout << r << endl;
    h = find_len(f, r, count);
    cout << count << endl; 
    
    return 0;
}
