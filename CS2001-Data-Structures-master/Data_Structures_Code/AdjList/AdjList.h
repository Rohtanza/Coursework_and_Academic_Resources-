#ifndef ADJLIST_ADJLIST_H
#define ADJLIST_ADJLIST_H

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class AdjList {

    int num;
    vector<list < char>> adjList;

public:

    AdjList(int num) : num(num), adjList(num) {}

    void setNodes() {
        for (int i = 0; i < num; ++i) {
            char A;
            cout << "Enter Node:", cin >> A;
            adjList[i].push_back(A);
        }
    }

    void AddNode(char listNode, char Node) {
        for (int i = 0; i < num; ++i) {
            if (adjList[i].front() == listNode) {
                adjList[i].push_back(Node);
                return;
            }
        }
        cout << "Cant find the Vertex" << endl;
    }

    void removeNode(char listNode, char remove) {
        for (int i = 0; i < num; ++i) {
            if (adjList[i].front() == listNode) {
                adjList[i].remove(remove);
                return;
            }
            cout << "Cant find the Vertex" << endl;

        }
    }

    void addnewvertex(char node) {
        list<char> newlist;
        newlist.push_back(node);
        int pos;
        cout << "Enter the pos where you want to insert", cin >> pos;
        adjList.insert((adjList.begin() + pos), newlist);
        num++;
    }


    void print() {
        for (int i = 0; i < num; ++i) {
            cout << "Vertex: " << i << " ";
            for (auto j: adjList[i]) {
                cout << j << "->";
            }
            cout << "NULL" << endl;
        }
    }



};

#endif //ADJLIST_ADJLIST_H
