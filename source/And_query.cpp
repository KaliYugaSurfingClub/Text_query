#include "And_query.h"

And_query::And_query(const Query &left, const Query &right) : Binary_query(left, right) {}

string And_query::rep() const {
    return string("(") + left_.rep() + " & " + right_.rep() + ")";
}

Result_query And_query::eval(const Text_query &text) const {
    Result_query left_res = left_.eval(text);
    Result_query right_res = right_.eval(text);
    auto res_lines = make_shared<std::set<size_t>>();

    if (!left_res.empty() && !right_res.empty()) {
        set_intersection(
            left_res.begin(), left_res.end(),
            right_res.begin(), right_res.end(),
            std::inserter(*res_lines, res_lines->begin())
        );
    }

    return {rep(), left_res.text(), res_lines};
}

Query operator&(const Query &left, const Query &right) {
    return Query(shared_ptr<Query_base>(new And_query(left, right)));
}
