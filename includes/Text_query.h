#ifndef QUERY_TEXT_QUERY_H
#define QUERY_TEXT_QUERY_H

#include <algorithm>

#include "use.h"
#include "Result_query.h"

class Text_query {
public:
    Text_query() = default;
    explicit Text_query(std::istream &file);

    //todo пусть возвращает просто сет
    Result_query query(const string &word) const;

private:
    shared_ptr<vector<string>> text_;
    map<string, shared_ptr<std::set<size_t>>> words_matched_lines_;
};


#endif //QUERY_TEXT_QUERY_H
