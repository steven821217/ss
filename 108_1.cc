#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

int max(vector<int> vec){
	int ans =0;
	for(auto x : vec){
		if(ans<x) ans= x;
	}
	return ans;
}

class Broom{
private:
	vector<int> vec ;
public:
 	Broom(){}
 	Broom& rshuffle(){
 		vector<int> rshuffle_vec;
 		while(vec.size()>0){
 			int i = rand()%vec.size();
 			rshuffle_vec.push_back(vec[i]);
 			vec.erase(vec.begin()+i);
 		}
 		vec = rshuffle_vec;
 		return *this;
 	}
 	Broom& operator+=(int i){
 		vec.push_back(i);
 		return *this;
 	}
 	friend ostream& operator<<(ostream& out ,Broom foo){
 		int mx = max(foo.vec);
 		for(int i =0;i<2*mx+2;i++){
 			for(auto x : foo.vec){
 				if(i==0) out<<string(x,'_')<<x<<string(x,'_');
 				else if(i<x+2) out<<string(x,' ')<<'I'<<string(x,' ');
 				else if(i<2*x+2) out<<string(2*x-i+1,' ')<<string(i-x-1,'/')<<'|'<<
 					string(i-x-1,'\\')<<string(2*x-i+1,' ');
 				else out<<string(2*x+1,' ');
 			}
 			out<<endl;
 		}
 		return out;
 	}
};
int main(){
	srand( static_cast<unsigned>(time(NULL)) ) ;
	int i , j , h ;
	Broom foo ;
	for ( i = 0 ; i < 3 ; ++i ) { // 三層
		for ( j = 0 ; j < 2 ; ++j ) { // 每次增加兩把掃把
			h = rand()%3 + 2 ;
			foo += h ; // 增加一把掃把，把頭高為 h
		}
		foo.rshuffle() ; // 打亂所有掃把次序
		cout << foo << endl ; // 印出所有掃把
	}
	return 0;
}