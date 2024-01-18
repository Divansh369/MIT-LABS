#include <iostream>
using namespace std;

int mat[20][20];

void bfs(int node, int n, int mat[][20], int vis[], int queue[], int &front,int &end){
    vis[node] = 1;
    queue[++front] = node;
    cout << "Pushed " << node << endl;

    for(int i = 0; i < n; i++){
        if(mat[node][i] == 1 && vis[i] != 1)
            bfs(i, n, mat, vis, queue, front,end);
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

    int queue[n], front=-1,end = m;
    bfs(1, n,mat, vis, queue, front,end);
    cout<<"Popped order: "<<endl;
    while(end>=0){
        cout<<queue[end--]<<endl;
    }

    return 0;
}
