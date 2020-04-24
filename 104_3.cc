#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
class Poem{
private:
	vector<wstring> poem;
public :
	Poem(wstring po){
		wstring p;
		for(int i=0;i<po.size();i++){
			if(po[i]!=L'，' and po[i] != L'='){
				p+=po[i];
			}
			if(p.size()==7){
				poem.push_back(p);
				p.clear();
			}
		}
	}
	friend wostream& operator<<(wostream& wout,Poem foo){
		int row=7,column =7;
		wout<<L"(a)"<<endl;
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
				if(i%2==0) wout<<foo.poem[i / 2][j];
				else if(j%2==0) wout<<foo.poem[j / 2][i];
				else wout<<L'　';
			}
			wout<<endl;
		}
		row=13,column=13;
		wout<<endl<<L"(b)"<<endl;
		for(int i=0;i<row;i++){
			for(int j =0;j<column;j++){
				if((i+j>=6 and j-i<=6 and i-j<=6 and i+j<=18)){
					if((i+j)%4==2) wout<<foo.poem[(i + j - 6) / 4][(6 - j + i) / 2];
					else if((i-j-2)%4==0) wout<<foo.poem[(i - j+6) / 4][(i+j-6) / 2];
					else wout<<L'　';
				}
				else wout<<L'　';
			}
			wout<<endl;
		}
		return wout;
	}
};
int main(){
	setlocale(LC_ALL, "zh_TW.UTF-8");
	Poem poem(L"依欄百侶讚山清，百里芳熏石上亭。讚賞石泉驚谷鳥，清風亭外鳥爭鳴") ;
	wcout << poem << endl ;
	return 0;
}