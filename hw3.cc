#include<iostream>
#include<string>
#include<sstream>
#include<fstream> 
#include<iomanip>
#include<math.h>

using namespace std;


class Gint{
	private:
		string snum;    // 各種整數字串
		int num;     //snum 所對應的10進位整數
	public:
		Gint(){};
		Gint(const string& sno) : snum(sno){
			num = snum2num(snum);
		}
		int get_num() const {return num;}
		string get_snum() const {return snum;}

		int snum2num(const string& sno) const ;

		friend istream& operator>> (istream& in ,Gint& foo) {
			in>>foo.snum;
			stringstream ss;
			int a ;
			if(foo.snum.substr(0,2)=="0x"){
				ss<<hex<<foo.snum;    //以16進位制讀入流中
			}else if(foo.snum.substr(0,2)=="0o"){
				foo.snum = foo.snum.substr(0,1)+foo.snum.substr(2);
				ss<<oct<<foo.snum;    //以8進位制讀入流中
			}else if(foo.snum.substr(0,2)=="0b"){
				int size = foo.snum.substr(2).size();
				int value = 0,j=0;
				for(int i = 0 ; i<size ; ++i){
					value = stoi(foo.snum.substr(2+i,1));
					value = pow(2,size-i-1)*value;
					j += value;
				}
				ss<<j;
			}else{
				ss<<foo.snum;
			}	
			ss>>foo.num;
			//cout<<a<<endl;       
    		return in ;
		}
			
		
};

int main(){
	ifstream infile("gint.dat");
	int sum;
	Gint foo;
	string line;
	istringstream istr;
	while(getline(infile,line)){
		istr.str(line);
		sum=0;
		while(istr>>foo) sum =sum +foo.get_num();
		istr.clear();
		cout<<"sum of "<<line<<" = "<<sum<<endl;
	}
}



























