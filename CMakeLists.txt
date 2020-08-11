cmake_minimum_required(VERSION 3.15)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Algorithm main.cpp tree/BinarySearchTree.cpp union_find/UnionFindTestHelper.h union_find/UnionFind1.h union_find/UnionFind2.h union_find/UnionFind3.h union_find/UnionFind4.h union_find/UnionFind5.h graph/DenseGraph.h graph/SpaseGraph.h graph/ReadGraph.h graph/Components.h graph/Path.h graph/ShortestPath.h graph2/Edge.h)