#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;
int str_to_int(string str){
	int ans;
	istringstream istr;
	istr.str(str);
	istr>>ans;
	return ans;
}

class Fraction {
private:
	int num ,den ;
	int gcd(int a,int b){
		if(a>b) return (a%b==0 ? b : gcd(a%b,b));
		else return (b%a==0 ? a : gcd(b%a,a));
	}
public :
	Fraction(){}
	Fraction(int n ,int d=1) : num(n) , den(d) {}
	int get_den(){return den;}
	int get_num(){return num;}

	friend ostream& operator<<(ostream& out ,Fraction foo){
		int gcd = foo.gcd(abs(foo.den),abs(foo.num));
		if(foo.den == 1) out<<foo.num;
		else if (foo.den< 0) out<< -foo.num/gcd<<"/"<<-foo.den/gcd;
		else out << foo.num/gcd<<"/"<<foo.den/gcd;
		return out;
	}
};

Fraction operator+( Fraction a, Fraction b){
	int num = a.get_num()*b.get_den()+b.get_num()*a.get_den();
	int den = a.get_den()*b.get_den();
    return Fraction(num,den);
}
Fraction operator-( Fraction a, Fraction b){
	int num = a.get_num()*b.get_den()-b.get_num()*a.get_den();
	int den = a.get_den()*b.get_den();
    return Fraction(num,den);
}

int main(){
	string line;
	cout<<"> ";
	getline(cin,line);
	istringstream istr;
	istr.str(line);
	string str_num;
	Fraction foo(0,1);
	string fra_str, num_str;
	int s=0,d=0;
	while(istr>>str_num){
		if(str_num.find('/')!=string::npos){
			s++;
			int den = str_to_int(str_num.substr(str_num.find('/')+1));
			int num = str_to_int(str_num.substr(0,str_num.find('/')));
			foo = foo + Fraction(num,den);
			fra_str +=(" + " + str_num);
		}else{
			d++;
			foo=foo- str_to_int(str_num);
			num_str += (" + "+ str_num);
		}

	}
	if(s>1 ) fra_str= "("+fra_str.substr(3)+ ")"+(d>0 ? " - " : "");
	else fra_str=(s==0 ? (d>0 ? "0 - ": "0") : fra_str.substr(3)+(d>0 ? " - ": ""));
	if(d>1 ) num_str = "(" + num_str.substr(3) + ")" ;
	else num_str= (d==0 ? "" : num_str.substr(3));

	cout<<fra_str<<num_str<<" = "<<foo<<endl;
	return 0; 
}