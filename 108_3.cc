#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

string int_to_str(int i){
	ostringstream ostr;
	ostr<<i;
	return ostr.str();
}
int str_find(string str){
	int s = str.find_first_not_of(str[0]);
	return (s<0 ? str.size() : s);
}
class Count{
private:
	string str;
	vector<string> vec;
public:
	Count(string lin ){
		str = lin;
		vec.push_back(lin);
		five_vec();
	}
	string find_nth(int i){
		return vec[i-1];
	}
	Count& reset(string new_str){
		str= new_str;
		vec.clear();
		vec.push_back(str);
		five_vec();
		return *this;
	}
	void five_vec(){
		for(int i=0;i<4;++i){
			int s = 0;
			string ans;
			while(1){
				str = str.substr(s);
				s = str_find(str);
				if(s==0) break;
				ans += int_to_str(s) + str[0];
			}
			vec.push_back(ans);
			str=ans;
		}
	}
	friend ostream& operator<<(ostream& out ,Count foo){
		for(int i =0;i<foo.vec.size();i++){
			cout<<" "<<i+1<<": ";
			cout<<string( (foo.vec[4].size()-foo.vec[i].size())/2,' ')<<foo.vec[i]<<endl;
		}
		return out;
	}
};
int main(){
	int maxn = 5 ;
	Count foo( "1" ) ; // 起始字串
	for ( int i = 0 ; i < maxn ; ++i ) {
		cout << setw(2) << i+1 << ": " << foo.find_nth(i+1) << endl ;
	}
	cout << endl << foo << endl ; // 輸出置中執行結果
	foo.reset("23") ; // 重新設定起始字串
	for ( int i = maxn-1 ; i >= 0 ; --i ) {
		cout << setw(2) << i+1 << ": " << foo.find_nth(i+1) << endl ;
	}
	cout << endl << foo << endl ; // 輸出置中執行結果
}