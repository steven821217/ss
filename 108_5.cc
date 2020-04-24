#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <sstream>
#include <vector>
using namespace std;
int abs(int a) {
return (a > 0 ? a : -a);
}
int gcd(int a, int b) {
a = abs(a); b = abs(b);
if (a > b)return (a % b == 0 ? b : gcd(b, a % b));
else return (b % a == 0 ? a : gcd(a, b % a));
}
class Fraction {
private:
int num, den;
public:
Fraction() {
}
Fraction(int a, int b = 1) {
if (b < 0) {
num = -a ;
den = -b;
}
else {
num = a;
den = b;
}
}
int getnum() const { return num; }
int getden() const { return den; }
friend Fraction abs(const Fraction& a) {
int use = gcd(a.num, a.den);
if (a.num >= 0 && a.den > 0) {
return Fraction(a.num / use, a.den / use);
}
else if (a.num >= 0 && a.den < 0) {
return Fraction(a.num / use, -a.den / use);
}
else if (a.num < 0 && a.den > 0) {
return Fraction(-a.num / use, a.den / use);
}
else {
return Fraction(-a.num / use, -a.den / use);
}
}
friend istream& operator<<(istream& in, Fraction& a) {
char del;
in >> a.num >> del >> a.den;
return in;
}
friend wostream& operator<<(wostream& wout, Fraction& a) {
int c = gcd(a.den, a.num);
wout << a.num/c << "/" << a.den/c;
return wout;
}
double val() {
return num;
}
friend Fraction operator+(const Fraction& a, const Fraction& b) {

return Fraction((a.getnum() * b.getden() + b.getnum() * a.getden()) , (a.getden() * b.getden()));
}
friend Fraction operator-(const Fraction& a, const Fraction& b) {

return Fraction((a.getnum() * b.getden() - b.getnum() * a.getden()), (a.getden() * b.getden()));
}
friend Fraction operator*(const Fraction& a, const Fraction& b) {

return Fraction((a.getnum() * b.getnum()), (a.getden() * b.getden()) );
}
friend Fraction operator/(const Fraction& a, const Fraction& b) {

return Fraction((a.getnum() * b.getden()) , (a.getden() * b.getnum()) );
}
Fraction& operator+=(const Fraction& a) {
return *this = *this + a;
}
Fraction& operator-=(const Fraction& a) {
return *this = *this - a;
}
Fraction& operator*=(const Fraction& a) {
num = num * a.num; den = den * a.den;
return *this;
}
Fraction& operator/=(const Fraction& a) {
num = num * a.den; den = den * a.num;
if (den < 0) { num *= -1; den *= -1; }
return *this;
}
friend bool operator<(const Fraction& a, const Fraction& b) {
return a.getnum() * b.getden() < b.getnum() * a.getden();
}
friend bool operator==(const Fraction& a, const Fraction& b) {
return a.getnum() * b.getden() == b.getnum() * a.getden();
}
friend bool operator>(const Fraction& a, const Fraction& b) {
return a.getnum() * b.getden() > b.getnum()* a.getden();
}
};
int main() {
setlocale(LC_ALL, "zh_TW.UTF-8");
wcin.imbue(locale(""));
wstring line1;
string line2; //line1是國字字串，line2是數學式字串

wcout << ">";
wcin >> line1;
wcout << line1 << endl << endl;
int count = 0; //計算+和-的數量
for (int i = 0; i < line1.length(); ++i) {
if (line1[i] == L'一') {
line2.push_back('1');
}
else if (line1[i] == L'二') {
line2.push_back('2');

}
else if (line1[i] == L'三') {
line2.push_back('3');
}
else if (line1[i] == L'四') {
line2.push_back('4');
}
else if (line1[i] == L'五') {
line2.push_back('5');
}
else if (line1[i] == L'六') {
line2.push_back('6');
}
else if (line1[i] == L'七') {
line2.push_back('7');
}
else if (line1[i] == L'八') {
line2.push_back('8');
}
else if (line1[i] == L'九') {
line2.push_back('9');
}
else if (line1[i] == L'加') {
line2.push_back('+');
count++;
}
else if (line1[i] == L'減') {
line2.push_back('-');
count++;
}
else if (line1[i] == L'分') {
line2.push_back('/');
++i;

}
}

Fraction sum(0, 1);
istringstream istr(line2);


char p = '\0';
int num = 0, den = 1;
//調換分子和分母，因為儲存時將兩個顛倒
for (int i = 0; i < line2.length(); ++i) {
if (line2[i] == '/') {
char a = line2[i - 1];
line2[i - 1] = line2[i + 1];
line2[i + 1] = a;
}
}
while (!istr.fail()) { //計算sum
istr >> num;
if (istr.peek() == '/') {
istr.ignore(1);
den = num;
istr >> num;
wcout << num << "/" << den; //列印分子
}
else {
den = 1;
wcout << num; //列印分母
}
Fraction f(num, den);

if (p == '\0' || p == '+') {
sum += f;
}
else {
sum -= f;
}
istr >> p;
if (count != 0) {
wcout << ' ' << p << ' '; //列印+-
count--;
}
}

wcout << " = "<< sum << endl;
istr.clear();
}
//三分之二減四加二分之五
//三加六分之三加九分之三減三分之四
//八分之五減二分之三減八分之一加三分之七