#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_VERTICES = 1001;

class Graph {
public:

    vector<int> adjacencyList[MAX_VERTICES]; // adjacencyList
    bool visited[MAX_VERTICES]; // Ž�� �� visited �ߴ����� ������ �����ϴ� array
    int visitOrder[MAX_VERTICES]; // Ž�� �� �湮�� ������ �����ϴ� array
    int currentIndex;
    int maxIndex;

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    void DFS(int vertex) {
        visited[vertex] = true;
        visitOrder[vertex] = ++currentIndex;
        for (int i = 0; i < adjacencyList[vertex].size(); i++) {
            int nextVertex = adjacencyList[vertex][i];
            if (!visited[nextVertex]) {
                DFS(nextVertex);
            }
        }
        if (vertex > maxIndex) {
            maxIndex = vertex;
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
        maxIndex = 0;
    }
};

int main() {
    int t, n, m, q, x, y;
    cin >> t ;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> q;
        Graph graph;
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            graph.addEdge(x, y);
        }
        for (int j = 0; j < q; j++) {
            cin >> x;
            graph.initialize(n);
            graph.DFS(x);
            cout << graph.maxIndex << endl;
        }
    }

    return 0;
}
