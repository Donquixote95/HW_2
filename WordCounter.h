#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class WordCounter {
    public:
        WordCounter();

        void InputText(const std::string text);

        int GetWordCount();
        int GetCharacterCount();
        int GetUniqueWordCount();
        int GetWordCount_OneWord(const char * word);

    protected:
        std::string text_input;

        int word_count{0};
        bool word_count_valid{false};

        int character_count{0};
        bool character_count_valid{false};

        int unique_word_count{0};
        bool unique_word_count_valid{false};
};