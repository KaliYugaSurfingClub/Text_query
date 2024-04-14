#ifndef QUERY_RESULT_QUERY_H
#define QUERY_RESULT_QUERY_H

#include "use.h"

class Result_query {
public:
    Result_query() = default;
    Result_query(string entry, const shared_ptr<vector<string>> &text, const shared_ptr<std::set<size_t>> &lines);

    shared_ptr<vector<string>> text();
    shared_ptr<const vector<string>> text() const;

    std::set<size_t>::iterator begin() {
        return lines_->begin();
    }

    std::set<size_t>::iterator end() {
        return lines_->end();
    }

    std::set<size_t>::const_iterator begin() const {
        return lines_->begin();
    }

    std::set<size_t>::const_iterator end() const {
        return lines_->end();
    }

    bool contains(size_t line_number);

private:
    string entry_report;
    //todo лучше валдеть текстом в котором искали??
    shared_ptr<vector<string>> text_;
    shared_ptr<std::set<size_t>> lines_;
};


#endif //QUERY_RESULT_QUERY_H
