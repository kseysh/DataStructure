#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_VERTICES = 1001;

class Graph {
private:
    vector<int> adjacencyList[MAX_VERTICES]; // adjacencyList
    int visitOrder[MAX_VERTICES]; // 탐색 시 방문한 순서를 저장하는 array
    int currentIndex;

public:
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void BFS(int vertex) {
        queue<int> q;
        q.push(vertex);
        visitOrder[vertex] = ++currentIndex; // 항상 방문과 push는 짝꿍인 것을 기억! pop과 짝꿍은 for,front
     
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int j = 0; j < adjacencyList[current].size();j++) {
                int nextVertex = adjacencyList[current][j];
                if (visitOrder[nextVertex]==0) {
                    visitOrder[nextVertex] = ++currentIndex;
                    q.push(nextVertex);
                }
            }
        }
    }

    int getVisitOrder(int vertex) {
        return visitOrder[vertex];// visitOrder에 방문한 순서를 저장해 놓았으므로 이렇게 하면 바로 출력이 가능하다.
    }

    void initialize(int N) {
        for (int i = 1; i <= N; i++) {
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
