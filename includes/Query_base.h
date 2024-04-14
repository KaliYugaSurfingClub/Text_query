#ifndef QUERY_QUERY_BASE_H
#define QUERY_QUERY_BASE_H

#include "Text_query.h"

class Query_base {
    friend class Query;

protected:
    virtual ~Query_base() = default;

private:
    virtual Result_query eval(const Text_query &text) const = 0;
    virtual string rep() const = 0;
};


#endif //QUERY_QUERY_BASE_H
