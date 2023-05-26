#include<iostream>
using namespace std;

struct vertex
{
	int vertexId;
	int matrixId;
	vertex* prev;
	vertex* next;

	vertex() {
		vertexId = matrixId = -1;
		prev = next = NULL;
	}
	vertex(int vertexId) {
		this->vertexId = vertexId;
		matrixId = -1;
		prev = next = NULL;
	}
};

struct edge
{
	edge* prev;
	edge* next;
	vertex* src;
	vertex* dst;

	edge() {
		prev = next = NULL;
		src = dst = NULL;
	}
	edge(vertex* src,vertex* dst) {
		this->src= src;
		this->dst= dst;
		prev = next = NULL;
	}
};

class v

int main() {
	


	return 0;
}
