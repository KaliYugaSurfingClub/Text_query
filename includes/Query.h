#ifndef QUERY_QUERY_H
#define QUERY_QUERY_H

#include "Query_base.h"

class Query {
public:
    explicit Query(const string &query);
    explicit Query(const shared_ptr<Query_base> &query);

    Result_query eval(const Text_query &text) const;
    string rep() const;

private:
    shared_ptr<Query_base> query_;
};

std::ostream &operator<<(std::ostream &os, const Query &query);
Query operator~(const Query &query);
Query operator&(const Query &left, const Query &right);
Query operator|(const Query &left, const Query &right);



#endif //QUERY_QUERY_H
