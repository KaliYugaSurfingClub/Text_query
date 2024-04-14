#include "Text_query.h"

Text_query::Text_query(std::istream &file) : text_(make_shared<vector<string>>()) {
    string line;
    while (getline(file, line)) {
        std::istringstream line_stream(line);
        size_t line_no = text_->size();
        string word;
        while (line_stream >> word) {
            shared_ptr<std::set<size_t>> &lines_with_word = words_matched_lines_[std::move(word)];
            if (!lines_with_word) {
                lines_with_word = make_shared<std::set<size_t>>();
            }
            lines_with_word->insert(line_no);
        }
        text_->push_back(std::move(line));
    }
}

Result_query Text_query::query(const string &word) const {
    static shared_ptr<std::set<size_t>> nodata;

    auto iter = words_matched_lines_.find(word);
    if (iter == words_matched_lines_.end()) {
        return {word, text_, nodata};
    }

    return {word, text_, iter->second};
}
