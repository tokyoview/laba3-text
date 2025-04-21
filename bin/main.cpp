#include <iostream>
#include <string>
#include "TString.h"

int main()
{
  TString a("aaaa", 4), str("IIIIIIII NeEd To kNow Now", 30);
  //std::cout << str;
  /* std::cin >> a;
  const char* aura = "ab";
  TString* ohio = new TString[a.WordCount(aura)+1];
  a.Split(aura, ohio);
  for (int i = 0; i < a.WordCount(aura)+1; ++i)
  {
    std::cout << ohio[i];
  } */
  TString b("trippi troppa", 20);
  std::cout << b;
  b = a * 4;
  std::cout << b;
  b = a + str;
  std::cout << b;
  /* str.PrintNumOfSymb();
  str.MostCommonChar();
  str.UniqueSymbols(); */
  return 0;
}