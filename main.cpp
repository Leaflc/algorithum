#include <iostream>
#include "union_find/UnionFindTestHelper.h"

using namespace std;

int main() {

    int n = 1000000;

    UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);
    UnionFindTestHelper::testUF5(n);
    return 0;
}
