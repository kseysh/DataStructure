#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_VERTICES = 1001;

class Graph {
public:

    vector<int> adjacencyList[MAX_VERTICES]; // adjacencyList
    bool visited[MAX_VERTICES]; // 탐색 시 visited 했는지의 정보를 저장하는 array
    int visitOrder[MAX_VERTICES]; // 탐색 시 방문한 순서를 저장하는 array
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
        return visitOrder[vertex];// visitOrder에 방문한 순서를 저장해 놓았으므로 이렇게 하면 바로 출력이 가능하다.
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
