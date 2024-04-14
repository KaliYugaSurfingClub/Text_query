#include "Or_query.h"

Or_query::Or_query(const Query &left, const Query &right) : Binary_query(left, right) {}

string Or_query::rep() const {
    string res = string("(") + left_.rep() + " | " + right_.rep() + ")";
    return res;
}

Result_query Or_query::eval(const Text_query &text) const {
    Result_query left_res = left_.eval(text);
    Result_query right_res = right_.eval(text);
    auto res_lines = make_shared<std::set<size_t>>(left_res.begin(), left_res.end());
    res_lines->insert(right_res.begin(), right_res.end());

    return {rep(), left_res.text(), res_lines};
}

Query operator|(const Query &left, const Query &right) {
    Query res = Query(shared_ptr<Query_base>(new Or_query(left, right)));
    return res;
}
