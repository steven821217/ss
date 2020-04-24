#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
	setlocale(LC_ALL,"zh_TW.UTF-8");
	const int MAX_W = 40;
	wstring line ;
	wifstream poem("vpoem.dat");
	wstringstream str1,poemstring[MAX_W];
	locale utf8("zh_TW.UTF-8");
	poem.imbue(utf8);
	wstring s,ss;
	int current = 0,no=0,max=0;
	int i,j;
	while(getline(poem,line)){
		if(max <line.length()) max=line.length();
		for(int i =0;i<line.length();++i){
			if(line[i]==L'：') ss=line.replace(i,1,L"　");		
			else if(line[i]==L'，') ss=line.replace(i,1,L"　");	
			else if(line[i]==L'？') ss=line.replace(i,1,L"　");	
			else if(line[i]==L'。') {
				ss=line.replace(i,1,L"　");
				ss=line.substr(current,i);
				current = i+1;
				poemstring[no++]<<ss;
				//wcout<<i<<ss<<endl;
			}
		}
		current =0;	
	}		
		for(i=0;i<no;++i){
			j=poemstring[i].str().size();
			if(j<max) poemstring[i]<<wstring(max-j,L'　');
		}
		for(j=0;j<max;++j){
			for(i =no-1;i>=0;--i){
				wcout<<poemstring[i].str()[j]<<L'　';
			}
			wcout<<endl;
		}
	return 0;
}