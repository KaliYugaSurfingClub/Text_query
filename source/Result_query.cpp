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

bool Result_query::empty() {
    return !lines_ || lines_->empty();
}

std::set<size_t>::iterator Result_query::begin() {
    return lines_->begin();
}

std::set<size_t>::iterator Result_query::end() {
    return lines_->end();
}

std::set<size_t>::const_iterator Result_query::begin() const {
    return lines_->begin();
}

std::set<size_t>::const_iterator Result_query::end() const {
    return lines_->end();
}

string Result_query::get_report() const {
    return entry_report;
}

std::ostream &operator<<(std::ostream &os, const Result_query &result) {
    os << result.get_report() << std::endl;
    for (const auto &line_number : result) {
        os << line_number << " - " << (*result.text())[line_number] << std::endl;
    }
    return os;
}
