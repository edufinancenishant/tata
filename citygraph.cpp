#include <iostream>
using namespace std;

#define MAX 10

void DFS(int v, int visited[], int n, int g[][MAX]) {
    visited[v] = 1;
    for(int i = 0; i < n; i++)
        if(g[v][i] == 1 && !visited[i])
            DFS(i, visited, n, g);
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string city[MAX];
    cout << "Enter city names:\n";
    for(int i = 0; i < n; i++)
        cin >> city[i];

    int g[MAX][MAX];
    cout << "Enter adjacency matrix (1 if flight exists, else 0):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    int visited[MAX] = {0};
    DFS(0, visited, n, g);

    int flag = 1;
    for(int i = 0; i < n; i++)
        if(!visited[i]) { flag = 0; break; }

    if(flag)
        cout << "\nThe graph is CONNECTED.\n";
    else
        cout << "\nThe graph is NOT connected.\n";

    return 0;
}
