#include <iostream>
#include "union_find/UnionFindTestHelper.h"
#include "graph/SpaseGraph.h"
#include "graph/DenseGraph.h"
#include "graph/ReadGraph.h"
#include "graph/Components.h"

using namespace std;


void graphTest() {
    int N = 20;
    int M = 100;

    srand(time(NULL));

    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }

    for (int v = 0; v < N; ++v) {
        cout << v << " : ";
        SparseGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }

    // Dense Graph
    DenseGraph g2(N, false);
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a, b);
    }

    for (int v = 0; v < N; ++v) {
        cout << v << " : ";
        DenseGraph::adjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void unionFindTest() {
    int n = 1000000;

    UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);
    UnionFindTestHelper::testUF5(n);
}

int main() {

    // TestG1.txt - g1 and g2
    string filename1 = "testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Components<SparseGraph> component1(g1);
    cout<<"TestG1.txt, Using Sparse Graph, Components Count: "<<component1.count()<<endl;
    return 0;
}