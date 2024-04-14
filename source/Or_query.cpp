#include "Or_query.h"

string Or_query::rep() const {
    return string("(") + left_.rep() + " | " + right_.rep() + ")";
}

Result_query Or_query::eval(const Text_query &text) const {
    Result_query left_res = left_.eval(text);
    Result_query right_res = right_.eval(text);
    auto res_lines = make_shared<std::set<size_t>>();

    if (!left_res.empty()) {
        res_lines->insert(left_res.begin(), left_res.end());
    }
    if (!right_res.empty()) {
        res_lines->insert(right_res.begin(), right_res.end());
    }

    return {rep(), left_res.text(), res_lines};
}

Query operator|(const Query &left, const Query &right) {
    return Query(shared_ptr<Query_base>(new Or_query(left, right)));
}
