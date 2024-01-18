#include <bits/stdc++.h>

using namespace std;
int adj_mat[100][100];
void topodfs(int node,int n,int mat[100][100],int vis[],int st[],int &top){
    vis[node]=1;
    
    for(int i=0;i<n;i++){
        if(adj_mat[node][i]==1 && !vis[i])
            topodfs(i,n,mat,vis,st,top);
    }
    st[++top]=node;
}
int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj_mat[i][j]=0;
    int t=n;
    while(t--){
        cout<<"Enter edge: "<<endl;
        int u,n1;
        cin>>u;
        cout<<"Enter number of edges to which it is directed else -1"<<endl;
        cin>>n1;
        if(n1==-1)
            continue;
        while(n1--){
            cout<<"Enter the directed edge: "<<endl;
            int v;
            cin>>v;
            adj_mat[u][v]=1;
        }
    }
    int st[n],top=-1;
    int vis[n]={0};
    for(int i=0;i<n;i++){
        if(!vis[i])
            topodfs(i,n,adj_mat,vis,st,top);
    }
    cout<<"Topological Sort Order in dfs is: "<<endl;
    while(top!=-1){
        cout<<st[top--]<<" ";
    }
    return 0;
}
