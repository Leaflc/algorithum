//
// 并查集 基于rank的优化 通过路径压缩提高查找速度
// Created by leaflc on 2020/4/29.
//

#ifndef ALGORITHM_UNIONFIND5_H
#define ALGORITHM_UNIONFIND5_H

#include <cassert>

namespace UF5 {

    class UnionFind {
    private:
        int *parent;
        int *rank;  // rank[i]表示以i为根的集合所表示的层数
        int count;

    public:
        UnionFind(int count) {
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {

            assert(p >= 0 && p < count);
            // 路径压缩 (path compression)
//            while (p != parent[p]) {
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;
            if (p != parent[p]) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;

            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[qRoot] < rank[pRoot]) {
                parent[qRoot] = pRoot;
            } else {
                // rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }

        }
    };
}
#endif //ALGORITHM_UNIONFIND5_H
