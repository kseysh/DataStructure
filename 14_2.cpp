#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_VERTICES = 101;

class Graph {
public:

    vector<int> adjacencyList[MAX_VERTICES]; // adjacencyList
    int visitOrder[MAX_VERTICES]; // 탐색 시 방문한 순서를 저장하는 array
    int currentIndex;
    int maxIndex;

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
    }

    void DFS(int vertex) {
        visitOrder[vertex] = ++currentIndex;
        for (int i = 0; i < adjacencyList[vertex].size(); i++) {
            int nextVertex = adjacencyList[vertex][i];
            if (visitOrder[nextVertex]==0) {
                DFS(nextVertex);
            }
        }
        if (vertex > maxIndex) {
            maxIndex = vertex;
        }
    }


    void initialize() {// 그냥 1000으로 하기
        for (int i = 0; i < 101; i++) {
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
            graph.initialize();
            graph.DFS(x);
            cout << graph.maxIndex << endl;
        }
    }

    return 0;
}
