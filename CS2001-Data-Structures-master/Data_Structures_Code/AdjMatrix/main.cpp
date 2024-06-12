#include <iostream>
#include "DirectedGraph.h"

int main() {
    int i;
    std::cout << "Enter Nodes num :", std::cin >> i;
    DirectedGraph g(i);

//    g.setNodesChar();
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addUnDirectedEdge(1,2);
    g.addUnDirectedEdge(1,1);




    g.printMatrix();
    return 0;
}
