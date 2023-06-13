#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_VERTICES = 1001;

class Graph {
private:
    vector<int> adjacencyList[MAX_VERTICES]; // adjacencyList
    bool visited[MAX_VERTICES]; // Ž�� �� visited �ߴ����� ������ �����ϴ� array
    int visitOrder[MAX_VERTICES]; // Ž�� �� �湮�� ������ �����ϴ� array
    int currentIndex;

public:
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void BFS(int vertex) {
        queue<int> q;
        q.push(vertex);
        visited[vertex] = true;
        visitOrder[vertex] = ++currentIndex;
     
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int j : adjacencyList[current]) {
                if (!visited[j]) {
                    visited[j] = true;
                    visitOrder[j] = ++currentIndex;
                    q.push(j);

                }
            }
            
        }
        
    }

    int getVisitOrder(int vertex) {
        return visitOrder[vertex];// visitOrder�� �湮�� ������ ������ �������Ƿ� �̷��� �ϸ� �ٷ� ����� �����ϴ�.
    }

    void initialize(int N) {
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
            visitOrder[i] = 0;
        }
        currentIndex = 0;
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    Graph graph;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        graph.initialize(N);
        graph.BFS(a);
        cout << graph.getVisitOrder(b) << endl;
    }

    return 0;
}
