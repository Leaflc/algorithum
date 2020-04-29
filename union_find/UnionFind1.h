//
// 并查集
// Created by leaflc on 2020/4/28.
//

#ifndef ALGORITHM_UNIONFIND1_H
#define ALGORITHM_UNIONFIND1_H

#include <iostream>
#include <cassert>

namespace UF1 {
    using namespace std;

    class UnionFind {

    private:
        int *id;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            id = new int[n];
            for (int i = 0; i < n; ++i) {
                id[i] = i;
            }
        }

        ~UnionFind() {
            delete[]id;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);

            if (pID == qID)
                return;

            for (int i = 0; i < count; ++i) {
                if (id[i] == pID)
                    id[i] = qID;
            }
        }
    };
}
#endif //ALGORITHM_UNIONFIND1_H
