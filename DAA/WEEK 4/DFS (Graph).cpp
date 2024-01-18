#include <iostream>
using namespace std;

int mat[20][20];

void dfs(int node, int n, int mat[][20], int vis[], int stack[], int &top){
    vis[node] = 1;
    stack[++top] = node;
    cout << "Pushed " << node << endl;

    for(int i = 0; i < n; i++){
        if(mat[node][i] == 1 && vis[i] != 1)
            dfs(i, n, mat, vis, stack, top);
    }
}

int main(){
	int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
	cin>> m;
    int vis[n] = {0};

    for(int i = 0; i < m; i++){
        cout << "Enter connecting vertices: " << endl;
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int stack[n], top = -1;
    dfs(1, n,mat, vis, stack, top);
    cout<<"Popped order: "<<endl;
    while(top>=0){
        cout<<stack[top--]<<endl;
    }

    return 0;
}
