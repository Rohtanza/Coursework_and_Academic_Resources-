//
// Created by rohtanza on 12/15/23.
//

#ifndef ADJMATRIX_DIRECTEDGRAPH_H
#define ADJMATRIX_DIRECTEDGRAPH_H

#include<iostream>
#include <vector>

class DirectedGraph {
    size_t numOfNodes;
    std::vector<std::vector<bool>> adjMat;
    std::vector<char> nodes;
public:
    explicit DirectedGraph(size_t numOfNodes) : numOfNodes(numOfNodes) {
        adjMat.resize(numOfNodes, std::vector<bool>(numOfNodes, false));
        nodes.resize(numOfNodes);
    }

//    void setNodesChar() {
//        for (int i = 0; i < nodes.size(); i++) {
//            std::cout << "Enter Nodes char: ";
//            std::cin >> nodes[i];
//        }
//    }


    void addDirectedEdge(int i, int j) {
        if (i > numOfNodes || j > numOfNodes)
            throw std::out_of_range("indexes are large then the nodes nums");
        adjMat[i][j] = true;
    }

    void removeDirectedEdge(int i, int j) {
        if (i > numOfNodes || j > numOfNodes)
            throw std::out_of_range("indexes are large then the nodes nums");
        adjMat[i][j] = false;
    }

    void addUnDirectedEdge(int i, int j) {
        if (i > numOfNodes || j > numOfNodes)
            throw std::out_of_range("indexes are large then the nodes nums");
        adjMat[i][j] = true;
        adjMat[j][i] = true;
    }

    void removeUnDirectedEdge(int i, int j) {
        if (i > numOfNodes || j > numOfNodes)
            throw std::out_of_range("indexes are large then the nodes nums");
        adjMat[i][j] = false;
        adjMat[j][i] = false;
    }

    void printMatrix() {
        std::cout << "\n";
        for (int i = 0; i < numOfNodes; i++) {
            std::cout << i << ":";
            for (int j = 0; j < numOfNodes; j++) {
                std::cout << adjMat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

};


#endif //ADJMATRIX_DIRECTEDGRAPH_H
