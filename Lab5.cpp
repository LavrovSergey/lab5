#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;


int main()
{
	ifstream f("lab.txt");
	char* m = new char[256];
	f.getline(m, 256);
	f.close();
	vector <double> equation;
	double y = 0; int  l = 0; bool flag = 0;
	while (m[l] > 0)
	{
		l++;
	}
	for (int i = 0; i < l; i++) 
	{
		if (m[i] == ' ')
		{
			if (isdigit(m[i - 1]))
			{
				if (flag)
					equation.push_back(-1 * y);
				else
					equation.push_back(y);
				y = 0;
				flag = 0;
			}
		}
		else
			if (m[i] == '+') 
			{
				if (!isdigit(m[i + 1]))
					equation.push_back(-0.1);
			}
			else if (m[i] == '-') 
			{
				if (isdigit(m[i + 1]))
					flag = 1;
				else
					equation.push_back(-0.2);
			}
			else if (m[i] == '/') 
			{
				equation.push_back(-0.3);
			}
			else 
			{   
				y *= 10;
				y += (double)(m[i] - 48);
			}
	}
	for (int i = equation.size(); i--; i >= 2) 
	{
		
		if ((equation[i] > -1 && equation[i] < 0) && (equation[i - 1] >= 0 || equation[i - 1] <= -1) && (equation[i - 2] >= 0 || equation[i - 2] <= -1)) 
		{
			if (equation[i] == -0.1) 
			{
				equation[i - 2] += equation[i - 1];
				equation.erase(equation.begin() + i - 1); equation.erase(equation.begin() + i - 1);
			}
			else if (equation[i] == -0.2) 
			{
				equation[i - 2] -= equation[i - 1];
				equation.erase(equation.begin() + i - 1); equation.erase(equation.begin() + i - 1);
			}
			else 	if (equation[i] == -0.3) 
			{
				equation[i - 2] = (int)equation[i - 2] / equation[i - 1];
				equation.erase(equation.begin() + i - 1); equation.erase(equation.begin() + i - 1);
			}
			i = equation.size();
		}
	}
	if (equation.size() == 1)
	{
		cout << equation[0];
		return 0;
	}
}