#include "Query.h"
#include "Word_query.h"

Query::Query(const string &query) : query_(new Word_query(query)) {}

Query::Query(const shared_ptr<Query_base> &query) : query_(query) {}

string Query::rep() const {
    string res = query_->rep();
    return res;
}

Result_query Query::eval(const Text_query &text) const {
    Result_query res = query_->eval(text);
    return res;
}
