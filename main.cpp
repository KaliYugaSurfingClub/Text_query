#include <bits/stdc++.h>
#include "Query.h"

using namespace std;

int main() {
    Query q = ~(Query("Hello") | Query("I"));
    ifstream file("../text.txt");
    Text_query tq(file);
    auto u = q.eval(tq);

    cout << u << endl;

    return 0;
}