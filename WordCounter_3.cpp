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

      //문장이 온점으로 끝나지 않는 경우, 온점을 붙여주는 처리
      if (text_input[(text_input.length()-1)] != '.'){
          std::string str_temp = ".";
          text_input.append(str_temp);
          }

      for (int i = 0; i < text_input.length(); i++){
        if (text_input[i] == ' ' || text_input[i] == '.' || text_input[i] == ','){
            // isalpha ; returns non-zero value if the character is an alphabetic character otherwise returns zero
              if (isalpha(text_input[i+1])){
                word_count++;
              }
              else{
                word_count++;
                ++i;
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

      //문장이 온점으로 끝나지 않는 경우, 온점을 붙여주는 처리
      if (text_input[(text_input.length()-1)] != '.'){
          std::string str_temp = ".";
          text_input.append(str_temp);
          }

      for (int i=0; i < text_input.length(); i++){
        if (text_input[i] == ' ' || text_input[i] == '.' || text_input[i] == ','){
          // substr ; returns a substring of the original string. extract a portion of a string from a specified position and a specified length
          string word = text_input.substr(start, i - start);  
          unique_words.insert(word);
          start = i+1;

          // ", "처럼 쉼표 뒤에 공백이 오는 경우
          while (! isalpha(text_input[i+1])){
            ++i;
            start = i+1;
          }
        }
      }
      unique_word_count = unique_words.size(); // size() ; the number of elements in the set

      // for(auto& u: unique_words) {
      //   cout << u << " ";
      // }
      // cout<<endl;

      return unique_word_count;
    }

int WordCounter::GetWordCount_OneWord(const char* word) {
    int count = 0;
    int i = text_input.find(word, 0);
    for (i; i < text_input.length();){
      // 문장의 앞 뒤로 알파벳이 아닌 경우, 즉 word가 독립적으로 있는 경우
      // text_input.find(word, 0)의 결과가 0이 될 경우, 즉 단어가 첫 번째에 바로 나올 경우
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
