/*!*****************************************************************************
\File q.hpp
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
namespace hlp2 {
    
    bool isUpper (const std::string &A); 

    std::string Swap (const int initial, const int width, 
                        std::string word, std::string suffix);

    std::string to_piglatin(std::string word);
}
