/*!*****************************************************************************
\File q.cpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Problem Solving with std::string s
\Par Programming Lab #3
\Date 26-01-2022

\Brief
  This program mimics the constructed lanuage game called Pig Latin. This allows
  people to spean an argot for fun. The driver file contains takes a word from
  the input file and pass by value to the function to_piglatin. A word is a 
  sequence of non-whitespace characters consisting of lower-case Latin characters
  (a through z), upper-case Latin characters (A through Z), digits (0 through 9),
  period (.), and apostrophe ('). Some examples of the word are: Zebra, doEsn't,
  PhD., 12asAl.', apple. 
  The output word is altered with a suffix like "-yay" or "-ay", per conditions:
  If the word starts with a vowel it will be suffixed with "-yay", like ape-yay 
  If the word has a vowel or y or Y elsewhere, the conversion is like so:
  Gobey -> obeyG-ay or bye -> yeb-ay or whisker -> iskerwh-ay
  if there are no vowels or the word starts with a y or Y, it is suffixed with 
  "-way" like so: yww -> yww-way or 12psr -> 12psr-way
  If the word starts with a capital letter, the output word must follow the same
  condition with a special clause if the letters were shifted:
  There -> Ereth-ay or Apple -> Apple-yay or Flower.y -> Ower.yfl-ay
  The file can only consist of functions pretaining to C++ standard library.
  This program utilizes a single function:
  
  - isUpper
      Returns a boolean expression. It takes in the starting letter of the word
      and checks if it is uppercase or lowercase. It converts the string to a 
      const pointer to a read only char to verify the case of the letter.

  - Swap
        This function conducts the swap of letters and includes the suffix at 
        the end of the output word. It also maintains the capitalization of 
        the first position of the original word like: 
        There -> Ereth-ay or Apple -> Apple-yay or Flower.y -> Ower.yfl-ay

  - to_piglatin
        Checks the word for the conditions and decides which condition the 
        word fits into and returns the converted word. Either: 
        First char is a vowel.
        Vowel is elsewhere in word and a vowel is detected before y Y or y Y is not 
        detected. 
        Non-vowel and or y Y is a first char.            
*******************************************************************************/

#include <iostream> // std::cout
#include <string>   // std::string

namespace hlp2 {

/*!*****************************************************************************
\brief
  Returns a boolean expression. It takes in the starting letter of the word and 
  checks if it is uppercase or lowercase. It converts the string to a const 
  pointer to a read only char to verify the case of the letter.

\param A
  Const reference to a read only string containing only the first letter of 
  the word.

\param c
  Const pointer to a read only char that contains the type casted string to 
  check if the subscript in A is a upper or lower cased letter and returns the 
  result.

*******************************************************************************/    
    bool isUpper (const std::string &A) {
        const char *c = A.c_str();
        return std::isupper(*c);
    }

/*!*****************************************************************************
\brief
  This function conducts the swap of letters and includes the suffix at the end
  of the to be returned output word. It also maintains the capitalization of the 
  first position of the original word like: 
  There -> Ereth-ay or Apple -> Apple-yay or Flower.y -> Ower.yfl-ay

\param initial
  Initial position of the set of letters to be swapped.

\param word_length
  Length of the word to be converted.

\param word
  The word from the input file to be converted.

\param suffix
  Contains the suffix to be appending at the end of the output word.

\param Case
  A boolean expression containing the result from the parsed value to the 
  function isUpper.

\param piglatin
  String to contain the letters to be shifted to the front of the string and to
  contain the output word after conversion to pig latin. A return of type string
  at the end of the function's execution time.
*******************************************************************************/
    std::string Swap (const int initial, const int word_length, 
                        std::string word, std::string suffix) {
        bool Case = isUpper(word.substr(0,1)); 
        std::string piglatin = word.substr(initial, word_length);
        if (Case) {
            word[0] = std::tolower(word[0]);
            word.erase(initial, word_length);
            piglatin[0] = std::toupper(piglatin[0]);
        }
        else {
            //normal stuff
            word.erase(initial, word_length);
        }
        return piglatin = piglatin + word + suffix;
    }

/*!*****************************************************************************
\brief
  Checks the word for the conditions and decides which condition the word fits 
  into and returns the converted word. Either: 
  First char is a vowel.
  Vowel is elsewhere in word and a vowel is detected before y Y or y Y is not 
  detected. 
  Non-vowel and or y Y is a first char.

\param word
  The word from the input file to be converted.

\param piglatin
  String to contain the word and the appended suffix before returning the string.

\param vowels
  String containing the list of vowels (upper and lower cased) to be checked 
  against.

\param let_y
  String containing y and Y to be checked against.

\param length
  The length of the word.

\param pos_vowel
  Position of the first vowels in the string, should there be one.

\param pos_y
  Position of the first let_y in the string, should there be one.
*******************************************************************************/
    std::string to_piglatin(std::string word) {
        std::string piglatin;
        std::string vowels = "AaEeIiOoUu";
        std::string let_y = "Yy";
        size_t length = word.length(), pos_vowel = word.find_first_of(vowels);
        size_t pos_y = word.find_first_of(let_y);

        //first char is vowel
        if (!pos_vowel) {
            return piglatin = word + "-yay";
        }
        //Vowel elsewhere in word
        else if (pos_vowel <= length) {  
            //vowel detected before y Y or Y is not detected
            if (pos_vowel < pos_y || pos_y == 0) {
                return Swap(pos_vowel, length, word, "-ay");
            }
            else {
                return Swap(pos_y, length, word, "-ay");
            }
        }
        //Non-vowel and only Y y as first char
        else { 
            return piglatin = word + "-way";
        }
    }
}