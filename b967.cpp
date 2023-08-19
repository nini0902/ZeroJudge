#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find_top(map<int, int> &T, vector<vector<int>> &F, int p) {
    for (int i = 0; i < p; i++) {
        if(T[i]==-1){
            return i;
        }
    }
    return 0;
}

int find_len(vector<vector<int>> &F, int num) {
    int max1 = 1;
    for (int i = 0; i < F[num].size(); i++) {
        if (F[num][i] != -1) {
            int len = find_len(F, F[num][i]) + 1;
            max1 = max(len, max1);
        }
    }
    return max1;
}

int main() {
    int p, parent, temp, top;
    cin >> p;
    vector<vector<int>> F(p, vector<int>(p,-1)); // F = family
    map<int, int> T; // T = top
    map<int, int> B; // B = bottom

    for (int i = 0; i < p; i++) {
        B[i] = -1;
        T[i] = -1;
    }

    while(cin >> parent >> temp) {
        B[parent] = 1;
        T[temp] = 1;
        for(int j = 0; j < p; j++){
            if(F[parent][j]==-1){
                F[parent][j] = temp;
                break;
            }
        }
    }

    top = find_top(T, F, p);

    int sum = 0, sum1 = 0;
    for(int i = 0; i < p; i++){
        cout <<i<<":";
        for(int j = 0; j < F[i].size(); j++){
            if(F[i][j]!=-1){
                int n = F[i][j];
                F[i][j] = find_len(F,n);
                cout << F[i][j] << " ";
            }
        }
    cout << endl;
    }
    
    return 0;
}