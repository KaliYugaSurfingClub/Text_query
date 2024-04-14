#ifndef QUERY_QUERY_BASE_H
#define QUERY_QUERY_BASE_H

#include "Text_query.h"

class Query_base {
    friend class Query;

protected:
    virtual ~Query_base() = default;

    string add_braces() {
        string res = rep();

        if (res.empty()) {
            return res;
        }

        vector<bool> conditions = {
            std::all_of(res.begin(), res.end(), [](char c) { return c == ' '; }) == 0,
            std::count(res.begin(), res.end(), ' ') == 0,
            res[0] == '(',
        };

        if (std::any_of(conditions.begin(), conditions.end(), [](bool v) { return v; })) {
            return res;
        } else {
            return string("(") + res + ")";
        }
    }

private:
    virtual Result_query eval(const Text_query &text) const = 0;
    virtual string rep() const = 0;
};


#endif //QUERY_QUERY_BASE_H
