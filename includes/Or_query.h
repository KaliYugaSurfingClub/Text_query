#ifndef QUERY_OR_QUERY_H
#define QUERY_OR_QUERY_H

#include "Binary_query.h"

class Or_query : public Binary_query {
    friend Query operator|(const Query &left, const Query &right);

    using Binary_query::Binary_query;

    string rep() const override;
    Result_query eval(const Text_query &text) const override;
};


#endif //QUERY_OR_QUERY_H
