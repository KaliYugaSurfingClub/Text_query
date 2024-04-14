#ifndef QUERY_NOT_QUERY_H
#define QUERY_NOT_QUERY_H

#include "Query_base.h"
#include "Query.h"

class Not_query : public Query_base {
    friend Query operator~(const Query &query);

    explicit Not_query(Query query) : query_(std::move(query)) {}

    string rep() const override;
    Result_query eval(const Text_query &text) const override;

    Query query_;
};


#endif //QUERY_NOT_QUERY_H
