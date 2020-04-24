#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

class Gpoint {
	private :
		int x , y ;
	public :
		Gpoint( int a = 0 , int b = 0 ) : x(a) , y(b) {}
		wstring path_to(Gpoint& from){
			int num_x = from.x - x;
			int num_y = from.y - y;
			wostringstream wistr;
			if(num_x<0 && num_y<0){
				wistr<<L"先往西走"<<abs(num_x)<<L"格，再往南走"<<abs(num_y)<<L"格"<<'\n';
			}else if(num_x>0 && num_y>0){
				wistr<<L"先往東走"<<abs(num_x)<<L"格，再往北走"<<abs(num_y)<<L"格"<<'\n';
			}else if(num_x>0 && num_y<0){
				wistr<<L"先往東走"<<abs(num_x)<<L"格，再往南走"<<abs(num_y)<<L"格"<<'\n';
			}else if(num_x<0 && num_y>0){
				wistr<<L"先往西走"<<abs(num_x)<<L"格，再往北走"<<abs(num_y)<<L"格"<<'\n';
			}else if(num_x>0 && num_y==0){
				wistr<<L"往東走"<<abs(num_x)<<L"格"<<'\n';
			}else if(num_x==0 && num_y>0){
				wistr<<L"往北走"<<abs(num_y)<<L"格"<<'\n';
			}else if(num_x==0 && num_y<0){
				wistr<<L"往南走"<<abs(num_y)<<L"格"<<'\n';
			}else if(num_x<0 && num_y==0){
				wistr<<L"往西走"<<abs(num_x)<<L"格"<<'\n';
			}else if(num_x==0 && num_y==0){
				wistr<<L"不動"<<'\n';
			}
			return wistr.str();
		}
		friend wostream& operator<<(wostream& out,Gpoint& foo){
			return out<<"["<<foo.x<<","<<foo.y<<"]";
		}
} ;
wstring int_to_str(int i){
	wostringstream ostr;
	ostr<<i;
	return ostr.str();
}
int random_no(int min,int max){
    int num = rand() % (max - min + 1) + min;
    return num;
}
int main(){
	srand(static_cast<unsigned>(time(NULL)));
	setlocale( LC_ALL , "zh_TW.UTF-8" ) ;

	Gpoint pt1 , pt2 ;
	int a , b , c , d ;
	for ( int i = 0 ; i < 5 ; ++i ) {
		a = random_no(0,10) ; b = random_no(0,10) ;
		c = random_no(0,10) ; d = random_no(0,10) ;
		pt1 = Gpoint(a,b) ; pt2 = Gpoint(c,d) ;
		wcout << i+1 << " : " << pt1 << " ---> " << pt2 <<'\n'
		<< pt1.path_to(pt2) <<'\n' ;
	}

}