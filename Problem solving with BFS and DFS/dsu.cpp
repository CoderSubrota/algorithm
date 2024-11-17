#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ;
int par[N] ;

void dsu_initialize(int n){ 
     for(int i=0; i<n; i++){
         par[i]=i; // Initialize each node as its own parent
     }
}

int find(int node){
   if(par[node]== node)  return node ; // If the node is the parent of itself, return it
    return find(par[node]) ; // Return the parent
}

int main() {
    dsu_initialize(4) ;
    cout << find(0) << endl;
    cout << find(1) << endl;
    cout << find(2) << endl;
    cout << find(3) << endl;
    return 0;
}