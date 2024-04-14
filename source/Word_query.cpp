#include "Word_query.h"

Word_query::Word_query(string word) : word_(std::move(word)) {}

Result_query Word_query::eval(const Text_query &text) const {
    return text.query(word_);
}

string Word_query::rep() const {
    return word_;
}
