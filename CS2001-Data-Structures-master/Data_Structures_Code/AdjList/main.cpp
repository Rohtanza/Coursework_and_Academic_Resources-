#include <iostream>
#include "AdjList.h"

int main() {
    int num = 9 ;
//    cout << "Enter the num of the nodes:", cin >> num;
    AdjList g(num);

    g.setNodes();
    g.AddNode('0', '2');
    g.AddNode('0', '3');
    g.AddNode('0', '5');
    g.AddNode('2', '4');
    g.AddNode('2', '5');
    g.AddNode('3', '5');
    g.AddNode('3', '6');
    g.AddNode('5', '6');
    g.AddNode('4', '5');
    g.AddNode('4', '8');
    g.AddNode('6', '7');
    g.AddNode('6', '9');
    g.AddNode('7', '5');
    g.AddNode('7', '4');
    g.AddNode('7', '8');
    g.AddNode('9', '7');
    g.AddNode('9', '8');
    g.print();






    return 0;
}
