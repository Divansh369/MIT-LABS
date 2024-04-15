#include <iostream>

using namespace std;

int main() {
    int n, k;
    cout << "Enter the number of modules, that is, dependent and independent combined: ";
    cin >> n;
    cout << "Enter the number of teams: ";
    cin >> k;

    // Initialize adjacency matrix and indegree array
    
    int adj_mat[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj_mat[i][j]=0;
    int indegree[n]= {0};

    // Input the dependencies
    for (int i = 0; i < k; i++) {
        int team_size;
        cout << "Enter the size of team " << i+1 << ": ";
        cin >> team_size;

        int last_module = -1;
        for (int j = 0; j < team_size; j++) {
            int module;
            cout << "Enter the module number: ";
            cin >> module;

            if (last_module != -1) { // Check for task dependency
                adj_mat[last_module][module] = 1;
                indegree[module]++;
            }
            last_module = module;
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

