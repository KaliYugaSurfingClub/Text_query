#ifndef QUERY_RESULT_QUERY_H
#define QUERY_RESULT_QUERY_H

#include "use.h"
#include <iostream>

class Result_query {
public:
    Result_query() = default;
    Result_query(string entry, const shared_ptr<vector<string>> &text, const shared_ptr<std::set<size_t>> &lines);

    shared_ptr<vector<string>> text();
    shared_ptr<const vector<string>> text() const;

    string get_report() const;

    bool empty();
    bool contains(size_t line_number);

    std::set<size_t>::iterator begin();
    std::set<size_t>::iterator end();
    std::set<size_t>::const_iterator begin() const;
    std::set<size_t>::const_iterator end() const;

private:
    //todo и запросом
    string entry_report;
    //todo лучше валдеть текстом в котором искали??
    shared_ptr<vector<string>> text_;
    shared_ptr<std::set<size_t>> lines_;
};

std::ostream &operator<<(std::ostream &os, const Result_query &result);


#endif //QUERY_RESULT_QUERY_H
