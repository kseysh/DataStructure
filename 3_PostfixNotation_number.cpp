#include <iostream>
using namespace std;

int main()
{
	int commandCount;
	string expression;
	cin >> commandCount >> expression;

	double* alphabetToNumberList = new double[commandCount];
	for (int i = 0; i < commandCount; i++) {
		cin >> alphabetToNumberList[i];
	}

	double* stack = new double[(int)expression.size()]{ 0 };
	int topIndex = -1;
	for (int i = 0; i < (int)expression.size(); i++)
	{
		if (expression[i] >= 'A' && expression[i] <= 'Z')
		{
			stack[++topIndex] = alphabetToNumberList[expression[i] - 'A'];
		}
		else
		{
			double b = stack[topIndex--];
			double a = stack[topIndex--];
			if (expression[i] == '+')
			{
				stack[++topIndex] = a + b;
			}
			else if (expression[i] == '-')
			{
				stack[++topIndex] = a - b;
			}
			else if (expression[i] == '*')
			{
				stack[++topIndex] = a * b;
			}
			else if (expression[i] == '/')
			{
				stack[++topIndex] = a / b;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << floor(stack[topIndex] * 100) / 100;

	delete[] alphabetToNumberList;
	delete[] stack;
}