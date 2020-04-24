#include <iostream>
#include <string>

using namespace std;
class Rotstr{
private:
	wstring wmath;
public:
	Rotstr(wstring x) : wmath(x){}
	wstring operator<<(int i){
		return wmath.substr(i,wmath.size())+wmath.substr(0,i);
	}
	wstring operator>>(int i){
		return wmath.substr(wmath.size()-i)+wmath.substr(0,wmath.size()-i);
	}
};
int main()
{
setlocale(LC_ALL, "zh_TW.UTF-8");
wstring nmath1 = L"中央大學數學系";
wstring nmath2(nmath1.rbegin(), nmath1.rend()); //反轉nmath1
Rotstr foo(nmath1), bar(nmath2);
for (int i = 0; i < nmath1.size(); ++i) {
wcout << (foo << i) << " " << (bar >> i) << endl;
}
return 0;
}