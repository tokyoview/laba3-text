#include <iostream>
#include "TString.h"
#include <string.h>


TString::TString(char* str_, int len_)
{
  if (len_ < 0)
    throw "Invalid lenght of a string!";
  if (str_ == 0 || len_ == 0)
  {
    this->str = nullptr;
    this->len = 0;
  }
  else
  {
    this->str = new char[len_+1];
    for (int i = 0; i < len_; ++i)
    {
      str[i] = str_[i];
    }
    str[len_+1] = '\0';
    if (len_ > strlen(str_))
      len = strlen(str_);
    else
      this->len = len_;
  }
}

TString::TString(const TString& p)
{
  len = p.len;
  str = new char[len + 1];
  for (int i = 0; i < len; i++)
  {
    str[i] = p.str[i];
  }
  str[len + 1] = '\0';
}

TString::TString(TString&& p)
{
  this->str = p.str;
  this->len = p.len;
  p.str = nullptr;
}

TString::~TString()
{
  if (str != nullptr)
    delete[] str;
  str = nullptr;
}

char* TString::GetStr()
{
  return str;
}

int TString::GetLen()
{
  return len;
}

void TString::SetStr(char* str_)
{
  if (str != nullptr) delete[] str;
  str = nullptr;
  if (str_ == nullptr) return;
  len = strlen(str_);
  str = new char[len+1]{0};
  strncpy(str, str_, len);
  str[len+1] = '\0';
}

TString TString::operator+ (const TString& p)
{
  int pos = 0;
  TString res;
  res.len = len + p.len;
  res.str = new char[res.len + 1];

  for (int i = 0; i < len; i++)
  {
    res.str[pos++] = str[i];
  }

  for (int i = 0; i < p.len; i++)
  {
    res.str[pos++] = p.str[i];
  }

  res.str[res.len + 1] = '\0';

  return res;
}

TString TString::operator* (int n)
{
  if (n <= 0) 
    throw "Invalid number";

  TString res;
  res.len = len * n;
  res.str = new char[res.len + 1];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < len; j++)
    {
      res.str[i * len + j] = str[j];
    }
  }
  res.str[res.len + 1] = '\0';
  return res;
}

TString& TString::operator= (const TString& p)
{
  if (this == &p) return *this;
  delete[] str;
  len = p.len;
  str = new char[len + 1];

  for (int i = 0; i < len; i++)
    str[i] = p.str[i];

  str[len + 1] = '\0';
  return *this;
}

bool TString::operator== (const TString& p)
{
  if (len != p.len) return false;
  bool flag = true;
  for (int i = 0; i < std::min(len, p.len); ++i)
    if (str[i] != p.str[i])
    {
      flag = false;
      break;
    }
  return flag;
}

bool TString::operator!= (const TString& p)
{
  return !(*this == p);
}

bool TString::operator> (const TString& p)
{
  int temp = std::min(len, p.len);
  bool flag = false;
  for (int i = 0; i < temp; i++)
  {
    if (!((str[i] - '\0') > (p.str[i] - '\0')))
    {  
      flag = false;
      break;
    }
  }
  return flag;
}

bool TString::operator< (const TString& p)
{
  return !(*this > p || *this == p);
}

char& TString::operator[](int i)
{
  if (i < 0 || i >= len)
    throw "Bad index!";
  return str[i];
}

std::ostream& operator<< (std::ostream& o, TString& s)
{
  //o << "Length of your string is:\t" << s.len << "\n";
  //o << s.str << std::endl;
  if (s.GetStr() == nullptr)
  {
    o << '\0';
    return o;
  }
  o << s.str;
  return o;
}

std::istream& operator>> (std::istream& i, TString& s)
{
  char buf[1024];
  std::cout << "Input length of your string:\t";
  i >> s.len;
  std::cout << "Now input your string:\t";
  i >> buf;
  s.SetStr(buf);
  return i;
}


int TString::WordCount(const char* word)
{
	//int len = GetLen();
	int l = strlen(word);
	int count = 0;
	if (l > len)
		return 0;
	int i = 0;
  //abababa
	while (i + l - 1 < len)
	{
		bool flag = true;
		if (str[i] == word[0])
		{
    for (int j = 1; j < l; ++j)
    {
      if (str[i + j] != word[j])
      {
        flag = false;
        break;
      }
    }
		}
		else
			flag = false;
		if (flag)
			count++;
    i++;
	}
	return count;
}

void TString::Split(const char* word, TString*& res)
{
	int temp = strlen(word);
	//int count = WordCount(word);
	int i = 0;
	int last = 0, n = 0, m = 0;
	while (i + temp - 1 < len)
  //while (i < len - temp)
  //abobababo
	{
		bool flag = true;
		if (str[i] != word[0])
		{
			i++;
      continue;
		}
    if (temp > 1)
      for (int j = 1; j < temp; ++j)
      {
        if (str[i + j] != word[j])
        {
          flag = false;
          break;
        }
      }
		if (flag)
		{
      //std::cout << "111" << '\n';
      m = 0;
      char* aboba = new char[i - last + 1]{0};
      //std::cout << i << "    " << last << std::endl;
			for (int k = last; k < i; k++)
			{
				aboba[m] = str[k];
        //std::cout << i << '\t' << m << std::endl;
				m++;
			}
      res[n].SetStr(aboba);
			last = i + temp;
			i = last;
      i++;
			n++;
		}
		else
			i++;
	}
  m = 0;
  char* aboba = new char[len - last + 1];
  //std::cout << i << "    " << last << std::endl;
  for (int k = last; k < len; k++)
  {
    aboba[m] = str[k];
    //std::cout << i << '\t' << m << std::endl;
    m++;
  }
  res[n].SetStr(aboba);
}

int TString::FirstIndex(const char* word)
{
  int temp = strlen(word);
	int i = 0;
	int res = -1;
	while (i + temp - 1 < len)
	{
		bool flag = true;
		if (str[i] != word[0])
		{
			i++;
      continue;
		}
    res = i;
		for (int j = 1; j < temp; ++j)
		{
			if (str[i + j] != word[j])
			{
				flag = false;
        res = -1;
				break;
			}
		}
		if (flag)
		{
      res = i;
      break;
		}
		else
			i++;
	}
  return res;
}

int* TString::CountSymbols() 
{
  int* a = new int[256];
  for (int i = 0; i < 256; ++i)
    a[i] = 0;

  for (int i = 0; i < len; ++i)
    a[str[i]]++;

  return a;
}

void TString::PrintNumOfSymb()
{
  int* a = CountSymbols();
  for (int i = 0; i < 256; ++i)
    if (a[i] != 0)
      std::cout << '"' << (char)i << '"' << " - " << a[i] << ", ";
  std::cout << std::endl;
}

void TString::UniqueSymbols()
{
  int* a = CountSymbols();
  int cnt = 0, m = 0;
  for (int i = 0; i < 256; ++i)
    if (a[i] != 0) cnt++;

  char* res = new char[cnt];
  for (int i = 0; i < 256; ++i)
  {
    if (a[i] != 0)
      res[m++] = (char)i;
  }
  for (int i = 0; i < m; ++i)
    std::cout << '"' << res[i] << '"' << ", ";
  std::cout << std::endl;
}

void TString::MostCommonChar()
{
  int* a = CountSymbols();
  int max = -100000, maxind = 0;
  for (int i = 0; i < 256; ++i)
    if (a[i] > max)
    {
      max = a[i];
      maxind = i;
    }
  std::cout << '"' << (char)maxind << '"' << std::endl;
}