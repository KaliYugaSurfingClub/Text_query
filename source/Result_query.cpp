#include "Result_query.h"

Result_query::Result_query
(string entry, const shared_ptr<vector<string>> &text, const shared_ptr<std::set<size_t>> &lines)
: entry_report(std::move(entry)), text_(text), lines_(lines) {}

shared_ptr<vector<string>> Result_query::text() {
    return text_;
}

shared_ptr<const vector<string>> Result_query::text() const {
    return text_;
}

bool Result_query::contains(size_t line_number) {
    return lines_->find(line_number) != lines_->end();
}