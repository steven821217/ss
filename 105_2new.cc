#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>
using namespace std;

class Coord{
private:
	double x ;
	double y ;
public :
	Coord(double a,double b) : x(a),y(b) {}
	void add_x(int s){x += s;}
	void add_y(int s){y += s;}
	friend wostream& operator<<(wostream& wout ,Coord foo){
		return wout<<L"位置 ： ["<<foo.x<<","<<foo.y<<"]";
	}
};
class Toy_Car {
  private:
    Coord pt;    //車子位置，Coord為二維座標結構
    double heading;  //車子方向 
    double speed;   //車子速度
  public:
    Toy_Car(double x = 0,double y = 0,double ang = 0,double s = 1) : pt(x,y) , heading(ang) , speed(s) {}
    Toy_Car forward(int s){
    	int x = (heading >=0 ? heading/90 : 4+heading/90);
    	if(x % 4 == 0) pt.add_x(s);
    	else if(x == 2) pt.add_x(-s);
    	else if(x == 1) pt.add_y(s);
    	else if(x == 3) pt.add_y(-s);
    	return *this;
    }
    Toy_Car backward(int s){
    	int x = (heading>0 ? heading/90 : 4+heading/90);
    	if(x % 4 == 0) pt.add_x(-s);
    	else if(x == 2) pt.add_x(s);
    	else if(x == 1) pt.add_y(-s);
    	else if(x == 3) pt.add_y(s);
    	return *this;
    }
    Toy_Car turn_right(){
    	heading -= 90;
    	if(heading == -360) heading=0;
    	return *this;
    }
    Toy_Car turn_left(){
    	heading += 90;
    	if(heading == 360) heading=0;
    	return *this;
    }
    friend wostream& operator<<(wostream& wout , Toy_Car foo){
    	return wout<<foo.pt<<L" 方向： "<<foo.heading;
    }

};

int main() {
setlocale(LC_ALL, "zh_TW.UTF-8");
Toy_Car car;
int i =1,k;
wcout << fixed<<setprecision(1);
wcout<<L"0 起始： "<<car<<endl;
while(1){
wcout<<i<<" ";
k=rand()%4;
if(k==0){
  wcout<<L"前進10秒： "<<car.forward(10);
}else if(k==1){
  wcout<<L"右轉： "<<car.turn_right();
}else if(k==2){
  wcout<<L"左轉：　"<<car.turn_left();
}else if(k==3){
  wcout<<L"後退10秒： "<<car.backward(10);
}
wcout<<endl;
usleep(1000000);
++i;
}
 return 0;
}