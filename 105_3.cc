#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
class Fraction {
private:
int num;
int den;
int gcd( int a,int b) {
if (a>b) return (a%b == 0 ? b : gcd(b , a%b));
else return (b%a ==0 ? a : gcd(a, b%a));
}
public:
Fraction() {}
Fraction( int n , int d = 1) : num(n) , den(d) {}
int get_den() {return den;}
int get_num() {return num;}
friend ostream& operator << (ostream& out,Fraction foo) {
int gcd = foo.gcd(abs(foo.den),abs(foo.num));
foo.num /= gcd; foo.den /= gcd;
if (foo.den == -1) out << foo.num;
else if (foo.den == -1) out << -foo.num;
else if (foo.den < 0) out << -foo.num <<"/"<<foo.den;
else out << foo.num/gcd << "/" << foo.den;
return out;
}
Fraction operator + ();
Fraction operator - ();
Fraction frastr_or_fraint(string foo) {
if (foo.find('/') == string::npos) {
int x;
istringstream istr;
istr.str(foo);
istr >> x;
return Fraction(x,1);
}
else {
int a,b;
char x;
istringstream istr;
istr.str(foo);
istr >> a >> x >> b;
return Fraction(a,b);
}
}
};
Fraction operator + (Fraction a,Fraction b) {
int num = a.get_num()*b.get_den() + b.get_num()*a.get_den();
int den = a.get_den()*b.get_den();
return Fraction(num,den);
}
Fraction operator - (Fraction a,Fraction b) {
int num = a.get_num()*b.get_den() - b.get_num()*a.get_den();
int den = a.get_den()*b.get_den();
return Fraction(num,den);
}
int main() {
ifstream infile("question.dat");
string foo;
while (getline(infile,foo)) {
string fra_num;
char x;
istringstream istr;
istr.str(foo);
istr >> fra_num;
cout << fra_num;
Fraction fra = fra.frastr_or_fraint(fra_num);
while (istr >> x >> fra_num) {
cout <<" "<<x<<" ";
cout << fra_num;
if ( x == '+') fra = fra + fra.frastr_or_fraint(fra_num);
if ( x == '-') fra = fra - fra.frastr_or_fraint(fra_num);
}
cout << "=" << fra << endl;
}
}