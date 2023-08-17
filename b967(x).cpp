#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find_top(vector<vector<int>> &F,int top[],int P){
    int top_num = -1;
    while(top_num==-1){
        for(int i = 0; i < P;i++){
            if(top[i]!=0){
                if(F[i][1]==-1){
                    top[i] = 0;
                    top[F[i][0]] = 1;
                    break;
                }
                else if(F[i][1]!=-1){
                    top_num = i;
                    return top_num;
                    break;
                }
            }
        }
    }
return top_num;
}

int find_len1(vector<vector<int>> F, int P, int top, int parent, vector<int>& visited) {
    int max_len = 0;
    visited[top] = 1; 
    for (int i = 0; i < P; i++) {
        if (F[top][i] != -1 && F[top][i] != parent && !visited[F[top][i]]) {
            int len = find_len1(F, P, F[top][i], top, visited) + 1;
            max_len = max(max_len, len);
        }
    }
    visited[top] = 0; 
    return max_len;
}

int find_len2(vector<vector<int>> F, int P, int top, int parent, vector<int>& visited) {
    int max1 = 0, max2 = 0, len1 = 0;
    visited[top] = 1; 
    for (int i = 0; i < P; i++) {
        if (F[top][i] != -1 && F[top][i] != parent && !visited[F[top][i]]) {
            int len = find_len2(F, P, F[top][i], top, visited) + 1;
            len1 = max(len1, len);
            if (len1 >= max1) {
                max2 = max1;
                max1 = len1;
            } else if (len1 > max2) {
                max2 = len1;
            }
        }
    }
    visited[top] = 0; 
    return max2;
}

int main(){

    int P,N,n;
    cin >> P;
    vector<vector<int>> F(P, vector<int>(P,-1)); 
    int T[P];

    while(cin>>N){
        cin >> n;
        T[n] = 0;
        for(int i = 0; i < P; i++){
            if(F[N][i]==-1){
                F[N][i] = n;
                break;
            }
        }
    }

    int a = find_top(F,T,P);

    vector<int> visited(P, 0);  

    int max1 = find_len1(F, P, a, -1, visited);  
    int max2 = find_len2(F, P, a, -1, visited);  

    int sum = max1 + max2;
    cout << sum << endl;

    return 0;
}



