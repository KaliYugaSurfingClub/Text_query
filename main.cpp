#include <bits/stdc++.h>
#include "Query.h"

using namespace std;

int main() {
    Query q = (Query("I") | Query("Hello")) & ~Query("sasha");

    ifstream file("../text.txt");
    Text_query tq(file);
    auto u = q.eval(tq);

    return 0;
}