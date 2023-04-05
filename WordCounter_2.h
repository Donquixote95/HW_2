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

        int word_count;
        int character_count;
        int unique_word_count;
};