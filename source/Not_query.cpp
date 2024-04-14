#include "Not_query.h"
#include "Word_query.h"

string Not_query::rep() const {
    string res = string("~(") + query_.rep() + ")";
    return res;
}

Result_query Not_query::eval(const Text_query &text) const {
    Result_query result_of_query = query_.eval(text);
    auto res_lines = make_shared<std::set<size_t>>();

    for (size_t i = 0; i < result_of_query.text()->size(); ++i) {
        if (!result_of_query.contains(i)) {
            res_lines->insert(i);
        }
    }

    return {rep(), result_of_query.text(), res_lines};
}

Query operator~(const Query &query) {
    auto res = Query(shared_ptr<Query_base>(new Not_query(query)));
    return res;
}
