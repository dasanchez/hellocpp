// HugeInteger class definitions

#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

class HugeInteger
{
  public:
    HugeInteger();
    void input(const int *, int);
    void output(); // print contents of numberArray
    void add(const int *, int);
    void subtract(const int *, int);
    bool isEqualTo(HugeInteger);
    bool isNotEqualTo(HugeInteger);
    bool isGreaterThan(HugeInteger);
    bool isLessThan(HugeInteger);
    bool isZero();

    const int numberLimit = 40;

  private:
    int numberArray[40];
    int numberSize;
};

#endif