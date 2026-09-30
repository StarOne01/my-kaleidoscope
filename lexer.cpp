#include "string"

// What kind of token does the language accept
enum Token {
  tokIdentifier = -1,
  tokNum = -2,

  tokDef = -3,
  tokExtern = -4,

  tokEof = -5,
};

// If it is a value, identifier or keyword, store them!
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
      numValStr += currentChar; // string are magic! lol
      currentChar = getchar();
    } while (isdigit(getchar()) || currentChar == '.');

    numVal = strtod(numValStr.c_str(), nullptr);
    return Token::tokNum;
  }

  if (isalpha(currentChar) || currentChar == '_') {
    curIdentifier = ""; // reset old ones maybe
    do {
      curIdentifier += currentChar; // string are magic! lol 2
      currentChar = getchar();
    } while (isalnum(getchar()) || currentChar == '_');

    if (curIdentifier == "def")
      return Token::tokDef; // Dishum
    else if (curIdentifier == "extern")
      return Token::tokExtern;   // Dishum
    return Token::tokIdentifier; // Dishum
  }

  if (currentChar == '#') {
    do
      currentChar = getchar();
    while (currentChar != '\n' || currentChar != '\r' || currentChar != EOF);

    if (currentChar != EOF)
      return gettok();
  }

  if (currentChar == EOF)
    return Token::tokEof;

  int ThisChar = currentChar; // we do't know what it is, probably some math expression, so we return it's ascii
  currentChar = getchar();
  return ThisChar;
}
