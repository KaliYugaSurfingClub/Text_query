#include "Word_query.h"

Word_query::Word_query(string word) : word_(std::move(word)) {}

Result_query Word_query::eval(const Text_query &text) const {
    Result_query res = text.query(word_);
    return res;
}

string Word_query::rep() const {
    return word_;
}
