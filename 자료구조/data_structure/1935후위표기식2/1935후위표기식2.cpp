#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<double>s;


int N;
string name;
string str;
double value1;
double value2;
double number[30];

int main()
{
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '*') {
			value2 = s.top();
			s.pop();
			value1 = s.top();
			s.pop();
			s.push(value1 * value2);
		}
		else if (str[i] == '+') {
			value2 = s.top();
			s.pop();
			value1 = s.top();
			s.pop();
			s.push(value1 + value2);
		}
		else if (str[i] == '-') {
			value2 = s.top();
			s.pop();
			value1 = s.top();
			s.pop();
			s.push(value1 - value2);
		}
		else if (str[i] == '/') {
			value2 = s.top();
			s.pop();
			value1 = s.top();
			s.pop();
			s.push(value1 / value2);
		}
		else {
			s.push(number[str[i] - 'A']);
		}
	}

	printf("%.2f", s.top());
	return 0;
}

