#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class View
{
  public:
    void menu(const vector<string>& menu, int& choice);
    void getNumber(int& num);
};

#endif
