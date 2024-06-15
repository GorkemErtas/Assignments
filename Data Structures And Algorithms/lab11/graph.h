#include <iostream>
/* 
Görkem Ertaþ
20070006004
*/

using namespace std;

template<class T>
class Vertex {
public:
    string name;
    T data;
    Vertex<T> *next;

    Vertex(string name, T data) {
        this->name = name;
        this->data = data;
        this->next = NULL;
    }
};

template<class T>
class Edge {
public:
    Vertex<T> *initialVertex;
    int connectionCount;

    Edge(Vertex<T> *initialVertex) {
        this->initialVertex = initialVertex;
        connectionCount = 0;
    }
};


template<class T>
class Graph {
public:
    int verticesCount;
    Vertex<T> **vertices;
    Edge<T> **edges;

    Graph(int verticesCount) {
        this->verticesCount = verticesCount;
        vertices = new Vertex<T> *[verticesCount];
    }


    /*
      Create edges by using the information on slide 22 and int main,
      instead of 1,2,3,4 you will use City A,City B,City C... City F vertices
      Store all the edges in an edge array
    */
    void createEdges(string edgeVerticesName[][2], int edgeNameCount) {
        // Allocate the necessary space for each vertex in the graph to represent edges
        edges = new Edge<T> *[verticesCount];
        for (int i = 0; i < verticesCount; i++) {
            edges[i] = new Edge<T>(new Vertex<T>(vertices[i]->name,vertices[i]->data));
        }
        for(int i=0; i<edgeNameCount; i++){
        	Vertex<T> initialVertex = getVertexByName(edgeVerticesName[i][1]);
		}
        //Your code to here
    }

    /*
       Create Vertex by assigning the names in verticesName as vertex's name
       and assigning the last character of the name as data
       If the name in the list is equal to City A
       Vertex name should be "City A"
       Vertex data should be 'A'
       Finally store all the vertex in vertices array
   */
    void createVertices(string *verticesNames, int verticesSize) {
		for(int i=0; i<verticesSize; i++) {
			string name = verticesNames[i];
			char data = verticesNames[i][name.length()-1];
			Vertex<T> *v = new Vertex<T>(name, data);
			verticesCount++;
			vertices[i] = v;
		}
    }

    void printGraph() {
        Edge<T> *edge;
        Vertex<T> *vertex;
        cout << "Graph Info " << endl;
        for (int i = 0; i < verticesCount; i++) {
            edge = edges[i];
            vertex = edge->initialVertex;
            for (int count = 0; count <= edge->connectionCount; count++) {
                cout << vertex->name << "->";
                vertex = vertex->next;
            }
            cout << endl;
        }
        cout << endl;
    }

    void clear() {
        for (int i = 0; i < verticesCount; i++) {
            delete vertices[i];
        }
        for (int i = 0; i < verticesCount; i++) {
            delete edges[i];
        }
    }

    // Search and return the vertex with the name given as parameter
    Vertex<T> *getVertexByName(string name) {
		for(int i=0; i<verticesCount; i++) {
			if(name == vertices[i]->name) {
				return vertices[i];
			}
		}
		return NULL;
    }

    // Search and return the edge with the name of the vertex given as parameter
    // Perform a linear search
    Edge<T> *getEdgeByInitialVertexName(string name) {
		for(int i=0; i<verticesCount; i++){
			if(edges[i]->initialVertex->name == name){
				return edges[i];
			}
		}
		return NULL;
    }
    // This is testing only function, do not use,edit or change it
    Edge<T>** getEdgeList(){
        return edges;
    }

};
