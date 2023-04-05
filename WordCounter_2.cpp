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
      word_count = 0;
      for (int i = 0; i < text_input.length(); i++){
        if (text_input[i] == ' ' || text_input[i] == '.' || text_input[i] == ','){
          // isalpha ; returns non-zero value if the character is an alphabetic character otherwise returns zero
          if (isalpha(text_input[i+1])){
            word_count++;
          }
          else{
            word_count++;
            i++;
          }
        }
      }
    return word_count;
  }

int WordCounter::GetCharacterCount() {
      character_count = 0;
      for (char c : text_input) { 
        if (c == ' ' || c == ',' || c == '.') {
          continue;
        }
        else {
          ++character_count;
        }
      }
    return character_count;
  }

int WordCounter::GetUniqueWordCount() {
      unique_word_count = 0;

      //python 기준 set인데 string type을 element로 가진다.
      unordered_set<string> unique_words; 
      int start = 0;

      for (int i=0; i < text_input.length(); i++){
        if (text_input[i] == ' ' || text_input[i] == '.' || text_input[i] == ','){
          // substr ; returns a substring of the original string. extract a portion of a string from a specified position and a specified length
          string word = text_input.substr(start, i - start);  
          unique_words.insert(word);
          start = i+1;
          while (! isalpha(text_input[i+1])){
            ++i;
            start = i;
          }
        }
      }
      unique_word_count = unique_words.size(); // size() ; the number of elements in the set
      return unique_word_count;
    }

int WordCounter::GetWordCount_OneWord(const char* word) {
    int count = 0;
    int i = text_input.find(word, 0);
    for (i; i < text_input.length();){
      if ((i == 0 || ! isalpha(text_input[i - 1])) 
          && ! isalpha(text_input[i + strlen(word)]))  // strlen ; returns an integer value that represents the length of the string
          {                                           
            ++count;
          }
        i += strlen(word);
        i = text_input.find(word, i);
    }
    return count;
  }
