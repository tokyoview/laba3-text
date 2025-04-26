#include <iostream>
#include <string.h>
#include "TString.h"
#include <ncurses.h>

void TryInput(int &a)
{
  while (a < 0)
  {
    std::cout << "Bad input! Try again: ";
    std::cin >> a;
  }
}

int main()
{
  int urow = 0, ucol = 0, ulen = 0;

  std::cout << "Please consider the bounds when inserting!" << std::endl;
  std::cout << "Enter number of column: ";
  std::cin >> ucol;
  TryInput(ucol);

  std::cout << "Enter number of row: ";
  std::cin >> urow;
  TryInput(urow);

  std::cout << "Enter length: ";
  std::cin >> ulen;
  TryInput(ulen);

  TString res(new char[ulen+1], ulen);
  char* buf = new char[ulen];

  initscr();

  int row, col;
  getmaxyx(stdscr, row, col);
  
  // перемещение курсора в стандартном экране
  move(urow - 1, ucol);
  char* horLine = new char[ulen];
  for (int i = 0; i < ulen; i++)
    horLine[i] = '-';
  printw(horLine); // вывод строки

  move(urow + 1, ucol);
  printw(horLine);

  move(urow, ucol - 1);
  printw("|");
  move(urow, ucol + ulen);
  printw("|");

  refresh(); // обновить экран
  //getch(); // ждём нажатия символа
  move(urow, ucol);
  scanw("%s", buf);


  endwin();
/*   TString a("aabaa", 4), str("IIIIIIII NeEd To kNow Now", 30);
  char test[] = "a,b,c";
  TString s(test, 5);
  TString* res = new TString[3];
  s.Split(",", res);
  for (int i =0; i < 3; i++)
  {
    std::cout << res[i] << std::endl;
  } */

  res.SetStr(buf);
  std::cout << res << std::endl;
  delete[] horLine;
  delete[] buf;
  return 0;
}