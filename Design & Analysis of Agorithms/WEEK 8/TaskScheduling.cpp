#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of modules,that is, dependent and independent combined: "<<endl;
    cin>>n;
    int adj_mat[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj_mat[i][j]=0;
    int t=n;
    while(t--){
        cout<<"Enter module: "<<endl;
        int u,n1;
        cin>>u;
        cout<<"Enter number of dependencies of the dependent module else enter -1 if independent module: "<<endl;
        cin>>n1;
        if(n1==-1)
            continue;
        while(n1--){
            cout<<"Enter the directed edge : "<<endl;
            int v;
            cin>>v;
            adj_mat[u][v]=1;
        }
    }
    int indegree[n]={0};
    //indegree calc
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj_mat[i][j]==1)
                indegree[j]++;
        }
    }
    int q[n],front=-1,rear=-1;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            if(front==-1 && rear==-1){
                front=0;
                rear=0;
                q[front]=i;
            }
            else
                q[++rear]=i;
    }
    }
    cout<<"Task scheduling order is:"<<endl;
    while(front<=rear){
        int node=q[front++];
        cout<<node<<" ";
        for(int i=0;i<n;i++){
            if(adj_mat[node][i]==1){
                indegree[i]--;
                if(indegree[i]==0){
                    if(front==-1 && rear==-1){
                        front=0;
                        rear=0;
                        q[front]=i;
                    }
                    else
                        q[++rear]=i;
            }
            }
        }
    }
    return 142;
}
