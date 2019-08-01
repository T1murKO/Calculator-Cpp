#include <cmath>
#include <string>
#include<iterator>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <sstream>
#include "stack.h"
using namespace std;


double calculate(const string);
string deleteSpaces(string);
double toDigit(const string);
int getPriority(const char);
double tempCalculating(const double, const double, char);
void reStacking(Stack<double>, Stack<char>, const string,double&);
void PriorityCalculation(Stack<double>&, Stack<char>&, const string, const size_t, string&,double&);
bool isoperator(const char);
bool isbracket(const char);
bool CheckInput(const string);
//clock_t elapsedTime(clock_t(*TimeFunc)(clock_t start), clock_t start);
//clock_t _start(clock_t nothing);
//clock_t _finish(clock_t start);
