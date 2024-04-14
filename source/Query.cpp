#include "Query.h"
#include "Word_query.h"

Query::Query(const string &query) : query_(shared_ptr<Query_base>(new Word_query(query))) {}

Query::Query(const shared_ptr<Query_base> &query) : query_(query) {}

string Query::rep() const {
    return query_->rep();
}

Result_query Query::eval(const Text_query &text) const {
    return query_->eval(text);
}

std::ostream &operator<<(std::ostream &os, const Query &query) {
    os << query.rep();
    return os;
}
