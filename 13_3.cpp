#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX_VERTICES = 10001;

class Graph {
private:
    vector<vector<bool>> adjacencyMatrix;
    vector<int> vertexList;

public:
    Graph() {
        adjacencyMatrix.resize(MAX_VERTICES, vector<bool>(MAX_VERTICES, false));
    }

    void insertVertex(int vertex) {
        if (adjacencyMatrix[vertex][vertex]) {
            cout << "Exist" << endl;
            return;
        }
        adjacencyMatrix[vertex][vertex] = true;
        vertexList.push_back(vertex);
    }

    void insertEdge(int vertex1, int vertex2) {
        if (adjacencyMatrix[vertex1][vertex2] || adjacencyMatrix[vertex2][vertex1]) {
            cout << "Exist" << endl;
            return;
        }

        adjacencyMatrix[vertex1][vertex2] = true;
        adjacencyMatrix[vertex2][vertex1] = true;
    }

    void eraseVertex(int vertex) {
        int vertexIdx = -1;
        for (int i = 0; i < vertexList.size(); i++) {
            if (vertex == vertexList[i]) {
                vertexIdx = i;
            }
            else if(adjacencyMatrix[vertex][vertexList[i]]){
                adjacencyMatrix[vertex][vertexList[i]] = false;
                adjacencyMatrix[vertexList[i]][vertex] = false;
            }
        }
        vertexList.erase(vertexList.begin() + vertexIdx);

    }

    void isAdjacentEven(int vertex) {
        int count = -1;
        for (int i = 0; i < vertexList.size(); i++) {
            if (adjacencyMatrix[vertex][vertexList[i]]) {
                count++;
            }
        }
        if (count % 2 == 0) {
            cout << "True ";
        }
        else {
            cout << "False ";
        }
        cout << count << endl;
    }

    void maxEdgeVertex() {
        int maxEdgeCount = -1;
        int maxVertexIdx = 200000;
        for (int i = 0; i < vertexList.size(); i++) {
            int currentEdgeCount = -1;
            for (int j = 0; j < vertexList.size(); j++) {
                if (adjacencyMatrix[vertexList[i]][vertexList[j]]) {
                    currentEdgeCount++;
                }
            }
            if (maxVertexIdx == 200000) {
                maxVertexIdx = i;
            }


            if (currentEdgeCount == maxEdgeCount) {
                if (vertexList[maxVertexIdx] > vertexList[i]) {
                    maxVertexIdx = i;
                }
            }
            else if (currentEdgeCount > maxEdgeCount) {
                maxEdgeCount = currentEdgeCount;
                maxVertexIdx = i;
            }
        }
        if (maxEdgeCount <= 0) {
            cout << -1 << endl;
        }
        else {
            cout << vertexList[maxVertexIdx] << endl;
        }
    }
};

int main() {
    int T;
    cin >> T;
    Graph graph;

    for (int i = 0; i < T; i++) {
        string command;
        cin >> command;

        if (command == "insertVertex") {
            int vertex;
            cin >> vertex;
            graph.insertVertex(vertex);
        }
        else if (command == "insertEdge") {
            int vertex1, vertex2;
            cin >> vertex1 >> vertex2;
            graph.insertEdge(vertex1, vertex2);
        }
        else if (command == "eraseVertex") {
            int vertex;
            cin >> vertex;
            graph.eraseVertex(vertex);
        }
        else if (command == "isAdjacentEven") {
            int vertex;
            cin >> vertex;
            graph.isAdjacentEven(vertex);
        }
        else if (command == "maxEdgeVertex") {
            graph.maxEdgeVertex();
        }
    }

    return 0;
}
