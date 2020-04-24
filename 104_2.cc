#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL,"en_US.UTF-8");
	const int N = 3;
	wstring foo[N] = { L"John Amy Tom Mary : 83 71 62 87",
						L"小明 小華 阿光 : 80 85 92",
						L"小美 Tony April 大牛 : 90 95 72 65"};

	for (int i = 0; i<N; i++) {
	vector<wstring> name;
	vector<int> grade;
	double total = 0;

	wstring str;
	wistringstream istr;
	istr.str(foo[i]);

	wcout << "[" << i+1 <<"[";

	while (istr >> str) {
		int a;
		wistringstream math_istr;
		math_istr.str(str);

		if (math_istr >> a) {
		total += a;
		grade.push_back(a);
		}
		else {
		if (str.find(':') == string::npos) name.push_back(str);
		}
	}

//name.size() = grade.size()
	wcout << " " <<round(total / grade.size()) << L" : ";
	for (int j = 0; j<name.size(); j++) {
		wcout << name[j] << ":" <<grade[j] << " ";
	}
	wcout << endl;
	}
return 0;
}