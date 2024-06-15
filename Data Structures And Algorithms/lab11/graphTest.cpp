#include "graph.h"

#define prettyPrint(value) (value?"Yes":"No")

int main() {
    string verticesNames[] = {"City A", "City B", "City C", "City D", "City E", "City F"};
    int verticesSize = sizeof(verticesNames) / sizeof(verticesNames[0]);
    Graph<char> graph = Graph<char>(verticesSize);
    string edgeVerticesName[][2] = {
            {"City A", "City B"},
            {"City A", "City D"},
            {"City B", "City D"},
            {"City C", "City B"},
            {"City D", "City C"},
            {"City E", "City C"},
            {"City E", "City F"},
            {"City F", "City F"},
    };
    graph.createVertices(verticesNames, verticesSize);
    graph.createEdges(edgeVerticesName, 8);
    Edge<char> **edgeList = graph.getEdgeList();
    cout << "Is test case 1 correct ? : " << prettyPrint(edgeList != NULL) << endl;
    cout << "Is test case 2 correct ? : " << prettyPrint(edgeList[0]->initialVertex->data == 'A') << endl;
    //City A->City B->City D-> connection count must be 2 as the "City A" vertex is the "initialVertex"
    cout << "Is test case 3 correct ? : " << prettyPrint(edgeList[0]->connectionCount == 2) << endl;
    cout << "Is test case 4 correct ? : " << prettyPrint(edgeList[1]->initialVertex->next->data == 'D') << endl;
    cout << "Is test case 5 correct ? : " << prettyPrint(edgeList[2]->initialVertex->next->data == 'B') << endl;
    cout << "Is test case 6 correct ? : " << prettyPrint(edgeList[3]->connectionCount == 1) << endl;
    cout << "Is test case 7 correct ? : " << prettyPrint(edgeList[3]->initialVertex->name == "City D") << endl;
    cout << "Is test case 8 correct ? : " << prettyPrint(edgeList[4]->initialVertex->next->next->data == 'F') << endl;
    cout << "Is test case 9 correct ? : " << prettyPrint(edgeList[5]->initialVertex->data == 'F') << endl;
    cout << "Is test case 10 correct ? : " << prettyPrint(edgeList[5]->initialVertex->next->data == 'F') << endl;

    graph.printGraph();
    graph.clear();
    return 0;
}

// Example output
//Graph Info
//City A->City B->City D->
//City B->City D->
//City C->City B->
//City D->City C->
//City E->City C->City F->
//City F->City F->
