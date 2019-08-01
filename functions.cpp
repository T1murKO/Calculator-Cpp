#include "Header.h"

bool CheckInput(const string expr) {
		int openingBrackets = 0;
		int closingBrackets = 0;
		int operatorCouner = 0;
		if (isoperator(expr[0]) && expr[0] != '-'&& !isbracket(expr[0])) {
			cout << "Error: wrong operator at first\n";
			return 1;
		}
		for (size_t i = 0; i != expr.length(); i++) {
			if (isoperator(expr[i]) && expr[i] == expr[i + 1] && !isbracket(expr[i])) {
				cout << "Error: to many operators in " << i+1 << " element, like " << expr[i] << expr[i + 1] << endl;
				return 1;
			}
			if (isbracket(expr[i])) {
				if (expr[i] == '(')
					openingBrackets++;
				else
					closingBrackets++;
			}
		}
		if (openingBrackets > closingBrackets) {
			cout << "Error: dont enough " << openingBrackets -closingBrackets  <<" closing brackets\n";
			return 1;
		}
		else if(closingBrackets > openingBrackets) {
			cout << "Erros: dont enough " << closingBrackets - openingBrackets << " opening brackets";
			return 1;
		}
		return 0;
}

double calculate(const string expr) {
	if (CheckInput(expr))
		return -666;
	
	Stack<double> digits;
	Stack<char> operators;
	string res = "";
	double answer = 0;
	for (size_t i = 0; i != expr.length(); i++) {
		PriorityCalculation(digits, operators, expr, i, res, answer);
	}
	if (digits.size() == 1)
		return digits.top();
	reStacking(digits, operators, expr, answer);
	return answer;
}//3*2+(3+4/2-(2+1))
 void PriorityCalculation(Stack<double>& digits, Stack<char>& operators, const string expr, const size_t i, string& res, double& answer) {
	 if (isdigit(expr[i]) && isoperator(expr[i + 1]) || isdigit(expr[i]) && i == expr.length()-1) {
		 res += expr[i];
		 digits.push(stod(res));
		 res = "";
	 }
	 else if ((isdigit(expr[i]) &&( isdigit(expr[i+1])) || expr[i+1] == '.' )||( expr[i] == '.') || (expr[i] == '-' && (i == 0 || !(isdigit(expr[i - 1]))))) {
		 res += expr[i];
	 }
	 else if (isbracket(expr[i])) {
		 if (expr[i] == '(')
			 operators.push(expr[i]);
		 else {
			 while (operators.top() != '(') {
				 double top = digits.top();
				 double prev = digits.prev();
				 double temp = tempCalculating(top, prev, operators.top());
				 digits.pop();
				 digits.pop();
				 operators.pop();
				 digits.push(temp);
			 }
			 operators.pop();
		 }
	 }
	 else if (isoperator(expr[i])) {
		 operators.push(expr[i]);
		 if (operators.size() >= 2 && getPriority(operators.top()) <= getPriority(operators.prev())) {
			 operators.pop();
			 double top = digits.top();
			 double prev = digits.prev();
			 double temp = tempCalculating(top,prev, operators.top());
			 digits.pop();
			 digits.pop();
			 operators.pop();
			 digits.push(temp);
			 operators.push(expr[i]);
		 }
	 }
	 }
 bool isoperator(const char i) {
	 switch (i) {
	 case'+':
		 return 1;
	 case'-':
		 return 1;
	 case'*':
		 return 1;
	 case'/':
		 return 1;
	 case'^':
		 return 1;
	 case'(':
		 return 1;
	 case')':
		 return 1;
	 default:
		 return 0;
	 }
 }
 bool isbracket(const char i) {
	 return i == '(' || i == ')' ? 1 : 0;
 }
void reStacking(Stack<double> digits,Stack<char> operators,const string expr,double& answer) {
	for (int i = 0; i != operators.size();) {
		double temp = tempCalculating(digits.top(), digits.prev(), operators.top());
		digits.pop();
		digits.pop();
		operators.pop();
		digits.push(temp);
	}
	answer = digits.top();
	return;
}
double tempCalculating(const double a,const double b,char c) {
	try {
		switch (c)
		{
		case '+':
			return a + b;
		case '-':
			return b - a;
		case '*':
			return a * b;
		case '/':
			if (a== 0){
				cout << "You cant divide by zero\n";
			system("pause");
			return -1;
		}
			return b / a;
		case'^':
			return pow(b, a);
		default:
			throw true;
			break;
		}
	}
	catch (bool a) {
		if (a == true) {
			cerr << "Error: Wrong operator" << endl;
			system("pause");
			return -1;
		}
	}
}
int getPriority(const char c) {
	try {
		switch (c) {
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '^':
			return 3;
		case '(':
			return 0;
			//case '^':
			//	return 3;
			//	break;
		default:
			throw true;
			break;
		}
	}
		catch(bool a){
			if (a == true) {
				cerr << "Error: Wrong operator" << endl;
				system("pause"); 
				return -1;
			}
		}
	}
	string deleteSpaces(string expr) {
		expr.erase(remove(expr.begin(), expr.end(), ' '), expr.end());
		return expr;
		}



















//clock_t elapsedTime(clock_t(*TimeFunc)(clock_t start), clock_t start = 0) {
//	return TimeFunc(start);
//}
//clock_t _start(clock_t nothing) {
//	return clock();
//}
//clock_t _finish(clock_t start) {
//	long double seconds = (long double)(clock() - start) / CLOCKS_PER_SEC;
//	std::cout << "Elapsed time " << seconds << " seconds\n";
//	return 0;
//}