//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;

//------------------------------

// Fix the following class
class Complex {
  public:
    Complex() {
      realNumber_ = 0;
      imaginaryNumber_ = 0;
    }

    Complex(int realNumber) {
      realNumber_ = realNumber;
      imaginaryNumber_ = 0;
    }

    Complex(int realNumber, int imaginaryNumber) {
      realNumber_ = realNumber;
      imaginaryNumber_ = imaginaryNumber;
    }

    void operator>>(std::string& rhs) const {
      std::string realNumberPart = "";
      if(realNumber_ < 0) {
        realNumberPart += "-";
      }
      realNumberPart += intToChar(absolute(realNumber_));

      std::string imaginaryNumberPart = "";
      if(imaginaryNumber_ < 0) {
        imaginaryNumberPart += "-";
      } else {
        imaginaryNumberPart += "+";
      }
      imaginaryNumberPart += intToChar(absolute(imaginaryNumber_));
      imaginaryNumberPart += "i";

      rhs = realNumberPart + imaginaryNumberPart;
    }

    void operator<<(const std::string& rhs) {
      //-0+0i
      //"1+1i" -> char 
      //char -> int 
      bool isNegativeRealNumber = false;
      bool isNegativeImaginaryNumber = false;
      char realNumberChar;
      char imaginaryNumberChar;
    
      if(rhs[0] == '-') {
        isNegativeRealNumber = true;
        realNumberChar = rhs[1];
      } else {
        realNumberChar = rhs[0];
      }

      realNumber_ = charToInt(realNumberChar);
      if(isNegativeRealNumber) {
        realNumber_ *= -1;
        imaginaryNumberChar = rhs[3];
        if(rhs[2] == '-') {
          isNegativeImaginaryNumber = true;
        }
      } else {
        imaginaryNumberChar = rhs[2];
        if(rhs[1] == '-') {
          isNegativeImaginaryNumber = true;
        }
      }

      imaginaryNumber_ = charToInt(imaginaryNumberChar);
      if(isNegativeImaginaryNumber) {
        imaginaryNumber_ *= -1;
      }
    }

    int absolute(int i ) const {
      if(i < 0) {
        return i * -1;
      } else {
        return i;
      }
    }

    char intToChar(int i) const {
      return (char)(i + 48);
    }

    int charToInt(char c) const {
      return (int)(c - 48);
    }

    int re() {
      return realNumber_;
    }

    int im() {
      return imaginaryNumber_;
    }

  private:
    int realNumber_;
    int imaginaryNumber_;
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
