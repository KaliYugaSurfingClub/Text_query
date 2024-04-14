#ifndef QUERY_WORD_QUERY_H
#define QUERY_WORD_QUERY_H

#include "Query_base.h"

class Word_query : public Query_base {
    friend class Query;

    explicit Word_query(string word);

    Result_query eval(const Text_query &text) const override;
    string rep() const override;

    string word_;
};


#endif //QUERY_WORD_QUERY_H
