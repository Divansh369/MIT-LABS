#include <iostream>
using namespace std;
 
int main()
{
	 cout<<"Adjacency Matrix.\n";
    int n, m;
    cout<<"\nEnter number of edges: ";
    cin >> n;
    cout<<"\nEnter number of vertices: ";
    cin >> m;
    int adjMat[n + 1][n + 1];
    for (int i = 0; i < n; i++) {
     for (int j=0;j<m;j++)
     {
	    int u, v;
        cout<<"\nEnter edge: ";
    	cin >> u;
    	cout<<"\nEnter vertice: ";
    	cin >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }}
    return 0;
}
