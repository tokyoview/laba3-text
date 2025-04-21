#include <iostream>

class TString
{
protected:
  char* str;
  int len;
public:
  //TString();
  TString(char* str_ = "", int len_ = 0);
  TString(const TString& p);
  TString(TString&& p);
  ~TString();

  char* GetStr();
  int GetLen();

  TString operator+ (const TString& p);
	TString operator* (int n);
	TString& operator= (const TString& p);
	bool operator== (const TString& p);
	bool operator!= (const TString& p);
  bool operator> (const TString& p);
  bool operator< (const TString& p);
  char& operator[](int i);

  int WordCount(const char* word);
  int NumberOfSplits(const char* word);
  void Split(const char* word, TString*& res);
  int FirstIndex(const char* word);
  int* CountSymbols();
  void PrintNumOfSymb();
  void UniqueSymbols();
  void MostCommonChar();
  
  friend std::ostream& operator<< (std::ostream& o, TString& s);
  friend std::istream& operator>> (std::istream& i, TString& s);
};