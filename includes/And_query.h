#ifndef QUERY_AND_QUERY_H
#define QUERY_AND_QUERY_H

#include "Binary_query.h"
#include "algorithm"

class And_query : public Binary_query {
    friend Query operator&(const Query &left, const Query &right);

    explicit And_query(const Query &left, const Query &right);

    string rep() const override;
    Result_query eval(const Text_query &text) const override;
};


#endif //QUERY_AND_QUERY_H
