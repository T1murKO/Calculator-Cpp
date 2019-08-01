#include "Header.h"
#include <ctime>
//100+10/5-(20+((-10*2)+14)+0/3)

int main(){
	/*clock_t start = elapsedTime(_start);*/
	cout << "==============================\nCalculator v.0.2\n\n >";
	string expression;
	getline(cin, expression);
	expression = deleteSpaces(expression);
	double res = calculate(expression);
	cout << res << endl;
	system("pause");
}