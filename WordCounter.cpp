#include "WordCounter.h"
#include <unordered_set>
#include <string.h>
#include <cctype>

using namespace std;

WordCounter::WordCounter()
            { }

void WordCounter::InputText(const string text){
    // Clear the previous text
    text_input.clear();

    text_input = text;
}

int WordCounter::GetWordCount() {
    if (!word_count_valid) {
      word_count = 0;
      long int pos = 0;
      while ((pos = text_input.find_first_not_of(" .,", pos)) != string::npos) { // string::npos == -1
        ++word_count;
        pos = text_input.find_first_of(" .,", pos);
      }
      word_count_valid = true;
    }
    return word_count;
  }


int WordCounter::GetCharacterCount() {
    if (!character_count_valid) {
      character_count = 0;
      for (char c : text_input) { // Range-based for loop
        if (c != ' ' && c != ',' && c != '.') {
          ++character_count;
        }
      }
      character_count_valid = true;
    }
    return character_count;
  }

int WordCounter::GetUniqueWordCount() {
    if (!unique_word_count_valid) {
      unique_word_count = 0;
      unordered_set<string> unique_words; //python 기준 set인데 string type을 element로 가진다.
      long int pos = 0;
      while ((pos = text_input.find_first_not_of(" .,", pos)) != string::npos) {
        long int end_pos = text_input.find_first_of(" .,", pos);
        string word = text_input.substr(pos, end_pos - pos);  // substr ; returns a substring of the original string. extract a portion of a string from a specified position and a specified length
        unique_words.insert(word);
        pos = end_pos;
      }
      unique_word_count = unique_words.size(); // size() ; the number of elements in the set
      unique_word_count_valid = true;
    }
    return unique_word_count;
  }

int WordCounter::GetWordCount_OneWord(const char* word) {
    int count = 0;
    long int pos = 0;
    while ((pos = text_input.find(word, pos)) != string::npos) {
      if ((pos == 0 || ! isalpha(text_input[pos - 1]))   // isalpha ; returns non-zero vlaue if the character is an alphabetic character otherwise returns zero
          && !isalpha(text_input[pos + strlen(word)])) { // strlen ; returns an integer value that represents the length of the string
        ++count;
      }
      pos += strlen(word);
    }
    return count;
  };
