#include <bits/stdc++.h>

using namespace std;
const int number_of_nodes = 100;

int leader[number_of_nodes], sz[number_of_nodes];
int n, q; // nodes, queries/updates

int find_leader(int node){
    if(leader[node] == node) return node;
    return leader[node] = find_leader(leader[node]);
}

bool same_component(int a, int b){
    return find_leader(a) == find_leader(b);
}

bool join(int a, int b){
    a = find_leader(a);
    b = find_leader(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    leader[b] = a;
    return true;
}


int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        leader[i] = i;
        sz[i] = 1;
    }
    int connected_components = n;
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        int type, a, b;
        cin >> type;
        if(type == 1){
            cin >> a >> b;
            if(join(a, b)){
                cout << "Successfully connected" << endl;
                connected_components--;
            }
            else cout << "Already connected" << endl;
        }
        else if(type == 2){
            cin >> a >> b;
            if(same_component(a, b))
                cout << "Connected" << endl;
            else cout << "Not connected" << endl;
        }
        else{
            cin >> a;
            cout << "Connected with: " << sz[find_leader(a)] << endl;
        }
    }
    return 0;
}

/*
6 9
5 4 9
1 4 1
1 5 4
1 2 2
4 2 3
4 3 5
3 2 3
3 6 8
2 6 7

-> ans : 17

6 9
1 2 1
2 4 15
4 5 6
5 6 9
1 6 14
1 3 9
2 3 10
4 3 11
6 3 2

-> ans : 33



*/
