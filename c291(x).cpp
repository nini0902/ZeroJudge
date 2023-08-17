#include <iostream>
#include <vector>
using namespace std;

int find_first(vector<bool> &G1, int t){
    for(int i = 0; i < t; i++){
        if(G1[i]){
            G1[i] = 0;
            return i;
        }
    }
return 0;
}

int find_G(vector<int> &G, vector<bool> &G1,int first_num){
    int count = 0, f;
    f = first_num;
    if(G[first_num]==f){
        count = 1;
        G1[G[first_num]] = 0;
        cout << G[first_num] << endl;
    }
    else{
        G1[G[first_num]] = 0;
        cout << G[first_num];
        count += find_G(G,G1,G[first_num]);
    }
    return 1;
}

int main(){
    int t;
    int count = 0;
    cin >> t;
    vector<int> G(t+1,0);
    vector<bool> G1(t+1,1);
    for(int i = 0; i < t; i++){
        cin >> G[i];
    }
    
    find_G(G,G1,find_first(G1,t));
return 0;
}
