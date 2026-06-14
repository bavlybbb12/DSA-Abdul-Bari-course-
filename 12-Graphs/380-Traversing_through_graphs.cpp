#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {

    private:
    int Vertices; 
    vector<vector<int>> adjList;
    
    public:
    Graph(int vertices) {
        Vertices = vertices;
        adjList.resize(Vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void BFS(int start) {

        vector<bool> visited(Vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }

            }

        }

    }

    void DFS(int start) {

        vector<bool> visited(Vertices, false);
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }

        }
    }
};