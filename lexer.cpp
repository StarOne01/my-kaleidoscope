#include "string"

// What kind of token does the language accept
enum Token {
  tokIdentifier = -1,
  tokNum = -2,

  tokDef = -3,
  tokExtern = -4,

  tokEof = -5,
};

// If it is a value or identifier, store them!
static double numVal;
static std::string curIdentifier;

// Now we get each token and figure what kind is this token
static int gettok() {
  int currentChar = ' ';

  while (currentChar == ' ')
    currentChar = getchar(); // throw away whitespaces!!

  if (isdigit(currentChar) || currentChar == '.') {
    std::string numValStr = ""; // we need a temporary location to show the
                                // const char thing before we convert to double
    do {
      numValStr += currentChar;
      currentChar = getchar();
    } while (isdigit(getchar()) || currentChar == '.');

    numVal = strtod(numValStr.c_str(), nullptr);
  }
}
