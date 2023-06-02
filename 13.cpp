#include<iostream>
#include<queue>
using namespace std;

struct vertex;
struct edge;
struct edgeNode;
class vertexList;

class edgeList {
public:

	edgeList();
	void insertEdge(edge* newEdge) {

	}
	void eraseEdge(edgeNode* delEdge) {

	}
	edgeNode* header;
	edgeNode* trailer;
};

struct vertex {
	bool visit;
	int vertexId;
	int degree;
	vertex* prev;
	vertex* next;
	edgeList incidentEdge;

	vertex() {
		vertexId = -1;
		degree = 0;
		prev = next = NULL;
		visit = false;
	}
	vertex(int vertexId) {
		this->vertexId = vertexId;
		degree = 0;
		prev = next = NULL;
		visit = false;

	}

};

struct edge {
	vertex* srcVertex;
	vertex* dstVertex;
	edgeNode* srcIncidentEdgeNode;
	edgeNode* dstIncidentEdgeNode;
	edgeNode* totalEdgeNode;
	edge() {
		srcVertex = dstVertex = NULL;
	}
	edge(vertex* src, vertex* dst) {
		this->srcVertex = src;
		this->dstVertex = dst;
	}
};

struct edgeNode {
	edge* edgeInfo;
	edgeNode* prev;
	edgeNode* next;
	edgeNode() {
		edgeInfo = NULL;
		prev = next = NULL;
	}
	edgeNode(edge* edgeInfo) {
		this->edgeInfo = edgeInfo;
		prev = next = NULL;
	}
};

class vertexList {
public:
	vertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}
	void insertVertex(vertex* newVertex) {
		newVertex->prev = trailer->prev;
		newVertex->next = trailer;
		trailer->prev->next = newVertex;
		trailer->prev = newVertex;
	}
	void eraseVertex(vertex* delVertex) {
		delVertex->prev->next = delVertex->next;
		delVertex->next->prev = delVertex->prev;
		delete delVertex;
	}

	vertex* findVertex(int vertexId) {
		for (vertex* curVertex = header->next; curVertex != trailer; curVertex = curVertex->next) {
			if (curVertex->vertexId == vertexId) {
				return curVertex;
			}
		}
		return NULL;
	}
private:
	vertex* header;
	vertex* trailer;
};

class edgeList {
public:
	edgeNode* header;
	edgeNode* trailer;

	edgeList() {
		header = new edgeNode();
		trailer = new edgeNode();
		header->next = trailer;
		trailer->prev = header;
	}

	void insertEdge(edge* newEdge) {
		edgeNode* newEdgeNode = new edgeNode(newEdge);
		newEdgeNode->prev = trailer->prev;
		newEdgeNode->next = trailer;
		trailer->prev->next = newEdgeNode;
		trailer->prev = newEdgeNode;
	}
	void eraseEdge(edgeNode* delEdge) {
		delEdge->prev->next = delEdge->next;
		delEdge->next->prev= delEdge->prev;
		delete delEdge;
	}

};

class graph {
private:
	vertexList vList;
	edgeList eList;
public:
	edge* findEdge(vertex* srcVertex, vertex* dstVertex) {
		if (srcVertex->degree < dstVertex->degree) {
			for (edgeNode* curEdge = srcVertex->incidentEdge.header->next; curEdge != srcVertex->incidentEdge.trailer; curEdge = curEdge->next) {
				if (curEdge->edgeInfo->dstVertex == dstVertex) {
					return curEdge->edgeInfo;
				}
			}
		}
		else {
			for (edgeNode* curEdge = dstVertex->incidentEdge.header->next; curEdge != dstVertex->incidentEdge.trailer; curEdge = curEdge->next) {
				if (curEdge->edgeInfo->dstVertex == srcVertex) {
					return curEdge->edgeInfo;
				}
			}
		}
		return NULL;
	}
	void isnertVertex(int vertexId) {
		if (vList.findVertex(vertexId) != NULL) {
			return;
		}
		vertex* newVertex = new vertex(vertexId);
		vList.insertVertex(newVertex);
	}
	void eraseVertex(int vertexId) {
		vertex* delVertex = vList.findVertex(vertexId);
		if (delVertex == NULL) {
			return;
		}
		for (edgeNode* curEdge = delVertex->incidentEdge.header->next; curEdge != delVertex->incidentEdge.trailer; curEdge = curEdge->next) {
			eList.eraseEdge(curEdge->edgeInfo->totalEdgeNode);
			if (curEdge == curEdge->edgeInfo->srcIncidentEdgeNode) {
				curEdge->edgeInfo->dstVertex->incidentEdge.eraseEdge(curEdge->edgeInfo->dstIncidentEdgeNode);
			}
			else {
				curEdge->edgeInfo->srcVertex->incidentEdge.eraseEdge(curEdge->edgeInfo->srcIncidentEdgeNode);
			}
			delete curEdge->edgeInfo;
		}
		vList.eraseVertex(delVertex);
	}
	void insertEdge(int srcVertexId, int dstVertexId) {
		vertex* srcVertex = vList.findVertex(srcVertexId);
		vertex* dstVertex = vList.findVertex(dstVertexId);
		if (srcVertex == NULL || dstVertex == NULL) {
			return;
		}
		if (findEdge(srcVertex, dstVertex) != NULL) {
			return;
		}
		edge* newEdge = new edge(srcVertex, dstVertex);

		srcVertex->incidentEdge.insertEdge(newEdge);
		dstVertex->incidentEdge.insertEdge(newEdge);
		eList.insertEdge(newEdge);
		newEdge->srcIncidentEdgeNode = srcVertex->incidentEdge.trailer->prev;
		newEdge->dstIncidentEdgeNode = dstVertex->incidentEdge.trailer->prev;
		newEdge->totalEdgeNode = eList.trailer->prev;
		srcVertex->degree++;
		dstVertex->degree++;
	}

	void eraseEdge(int srcVertexId, int dstVertexId) {
		vertex* srcVertex = vList.findVertex(srcVertexId);
		vertex* dstVertex = vList.findVertex(dstVertexId);
		if (srcVertex == NULL || dstVertex == NULL) {
			return;
		}

		edge* delEdge = findEdge(srcVertex, dstVertex);

		if (delEdge == NULL) {
			return;
		}

		srcVertex->incidentEdge.eraseEdge(delEdge->srcIncidentEdgeNode);
		dstVertex->incidentEdge.eraseEdge(delEdge->dstIncidentEdgeNode);
		eList.eraseEdge(delEdge->totalEdgeNode);
		srcVertex->degree--;
		dstVertex->degree--;
		delete delEdge;
	}

	void DFS(vertex* curVertex) {
		curVertex->visit = true;
		for (edgeNode* e = curVertex->incidentEdge.header->next; e != curVertex->incidentEdge.trailer; e = e->next) {
			if (curVertex == e->edgeInfo->srcVertex) {
				if (e->edgeInfo->dstVertex->visit != true) {
					DFS(e->edgeInfo->dstVertex);
				}
			}
			else {
				if (e->edgeInfo->srcVertex->visit != true) {
					DFS(e->edgeInfo->srcVertex);
				}
			}
		}
	}

	void BFS(int vertexId) {
		vertex* v = vList.findVertex(vertexId);
		queue<vertex*> que;
		que.push(v);
		v->visit = true;
		while (!que.empty()) {
			vertex* curVertex = que.front();
			que.pop();
			for (edgeNode* e = curVertex->incidentEdge.header->next; e != curVertex->incidentEdge.trailer; e = e->next) {
				if (curVertex == e->edgeInfo->srcVertex) {
					if (e->edgeInfo->dstVertex->visit != true) {
						que.push(e->edgeInfo->dstVertex);
						e->edgeInfo->dstVertex->visit = true;
					}
				}
				else {
					if (e->edgeInfo->srcVertex->visit != true) {
						que.push(e->edgeInfo->srcVertex);
						e->edgeInfo->srcVertex->visit = true;
					}
				}
			}
		}
	}

	int main() {

		return 0;
	}
};

