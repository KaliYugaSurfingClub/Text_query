#ifndef QUERY_BINARY_QUERY_H
#define QUERY_BINARY_QUERY_H

#include "Query_base.h"
#include "Query.h"

class Binary_query : public Query_base {
protected:
    Binary_query(Query left, Query right) : left_(std::move(left)), right_(std::move(right)) {}

    Query left_;
    Query right_;
};


#endif //QUERY_BINARY_QUERY_H
