#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define VERTEX 10

int E = 0;
struct EDGE{int a, b, w;} e[10000];
bool operator < (EDGE a, EDGE b){ return a.w < b.w; }

int parent[VERTEX];
void initial(){
    for(int i = 0; i < VERTEX; ++i)
        parent[i] = i;
}
int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}
void uni(int a, int b){
    parent[find(a)] = find(b);
}

void kruskal(){
    sort(e, e+E);
    initial();

    int sum = 0;
    for(int i = 0; i < E; ++i){
        if(find(e[i].a) == find(e[i].b)) continue;
        uni(e[i].a, e[i].b);
        sum += e[i].w;
    }
    cout << sum << '\n';
}


int main(){
    string s;
    while(cin >> s){
        if(s == "end") break;
        int edge1 = stoi(s), edge2, weight;
        cin >> edge2 >> weight;
        e[E].a = edge1;
        e[E].b = edge2;
        e[E++].w = weight;
    }
    kruskal();
    return 0;
}

