#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;
class Num_Base {
private:
int num;
//wstring wnum;
public:
Num_Base() {}
void setno(int n) {
num = n;
/*
wostringstream wostr;
wostr << n;
wnum = wostr.str();
*/
}
wstring base (int b) {
int max = num%10 > num/10 ? num%10 : num/10;
if (max >= b) return L"*";
int s = num / 10*b + num% 10;
/*
int s = 0;
for (int x = 0; x<wnum.size() ; x++) {
s += (wnum[x] - '0') * pow(b, (wnum.size() - x -1));
}
*/
wostringstream wostr;
wostr << s;
return wostr.str();
}
};
int main() {
Num_Base no;
setlocale(LC_ALL, "en_US.utf-8");
wcout << setw(4) << " ";
for (int b = 2;b <= 12; ++b) {
wcout << setw(2) << b << L"進位";
}
wcout << endl;
for (int n = 10; n <= 40; ++n) {
no.setno(n);
wcout << setw(2) << n;
for (int b = 2;b <= 12 ; ++b) {
wcout << setw(6) << no.base(b);
}
wcout << endl;
}
}