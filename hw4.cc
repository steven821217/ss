#include <iostream>
#include <cassert>
using namespace std;

class Fraction{
	private:
	//  分子，分母
        int num ,den ;
        
        
	public :
		Fraction() {}
		Fraction(int a,int b=1) : num(a),den(b){
			assert(den!=0);
    		if(b<0) {num *= -1;den *= -1;}
		}
		friend Fraction ab(const Fraction& a);
		int get_num() const {return num;}
    	int get_den() const {return den ;}	    	
    
		friend ostream& operator<<(ostream& out ,const Fraction& foo){
    		
    		return out<<foo.num<<"/"<<foo.den;
    	}
    	double val(){
    		return static_cast<double>(num) / static_cast<double>(den);
    	}

};


int gcd(int a, int b) {
    if (a < 0) a = abs(a);
    if (b < 0) b = abs(b);
    if(a>b) return(a%b==0 ? b : gcd(b,a%b));
    else    return(b%a==0 ? a : gcd(a,b%a));
}


Fraction operator+(const Fraction& a,const Fraction& b) {
	int n = a.get_num()*b.get_den()+b.get_num()*a.get_den();
	int d = a.get_den()*b.get_den();
	int divisor = gcd(n,d);
	return Fraction(n/divisor,d/divisor);
}
Fraction operator*(const Fraction& a,const Fraction& b){
	int n = a.get_num()*b.get_num();
	int d = a.get_den()*b.get_den();
	int divisor = gcd(n,d);
	return Fraction(n/divisor,d/divisor);
}
Fraction operator-(const Fraction& a,const Fraction& b){
	int n = a.get_num()*b.get_den()-b.get_num()*a.get_den();
	int d = a.get_den()*b.get_den();
	int divisor = gcd(n,d);
	return Fraction(n/divisor,d/divisor);
}
Fraction operator/(const Fraction& a,const Fraction& b){
	int n = a.get_num()*b.get_den();
	int d = a.get_den()*b.get_num();
	int divisor = gcd(n,d);
	return Fraction(n/divisor,d/divisor);
}
template<typename T>
bool operator>(Fraction& a, T b) {
    
    if (a.get_num() > b* a.get_den()) return true;
    else return false;
}


/*Fraction abs(Fraction a) {
    if (a.get_num() >= 0 && a.get_den() >= 0) {
        return Fraction(a.get_num(), a.get_den());
    }
    else if (a.get_num() >= 0 && a.get_den() < 0) {
        return Fraction(a.get_num(), -1 * a.get_den());
    }
    else if (a.get_num() < 0 && a.get_den() >= 0) {
        return Fraction(-1 * a.get_num(), a.get_den());
    }
    else {
        return Fraction(-1 * a.get_num(), -1 * a.get_den());
    }
}*/
Fraction ab(const Fraction& a){return Fraction(abs(a.num),abs(a.den));}


Fraction f(const Fraction& x) {return x*x-Fraction(3,4); } 
Fraction df(const Fraction& x) {return 2*x;}
template<typename T>
T Newton_Iteration(T x0){
	T x1 , dx = 1;
	while(dx > 0.0001){
		x1 = x0 -f(x0) / df(x0);
		dx = ab(x1-x0);
		x0 = x1 ;
	}
	return x0 ;
}




int main(){
	Fraction x(1);     //牛頓迭代法出值

	Fraction sol = Newton_Iteration <Fraction> (x);
	
	cout<<sol<<" = "<<sol.val()<<endl;

}