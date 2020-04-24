#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(){
	srand(static_cast<unsigned>(time(NULL)));
	string str ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int i ,j;
	for(i=0 ; i<11 ;++i){
		int k=0,sum=0;
		string s;
		cout<<setw(2)<<i<<"> ";
		for(int j=0;j<rand()%11+20;++j){
			s += str[rand()%str.size()];
		}
		cout<<s<<endl<<" > ";
		for(int i = 0; i<s.size();++i){
			if(s[i]-'0'>=0 and s[i]-'0'<=9){
				k++;
				sum += s[i]-'0';
				cout<<(k==1?"":" + ")<<s[i];
			}
		}
		if(k>0) cout<<" = "<<sum<<endl;
		else cout<<"no number and sum =0"<<endl;
	}
	return 0;
}