
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
wchar_t hh = static_cast<wchar_t>(9473);
wchar_t vv = static_cast<wchar_t>(9475);
wchar_t mu = static_cast<wchar_t>(9531);
wchar_t md = static_cast<wchar_t>(9523);
wchar_t sw = static_cast<wchar_t>(9495);
wchar_t se = static_cast<wchar_t>(9499);


class Flag{
    private:
        vector<int> vec;
    public:
        Flag(){}
        void sval(int n){
            vec.clear();
            ostringstream sstr;
            sstr<<n;
            for(auto x : sstr.str()){
                vec.push_back(x-'0');
            }
        }
        friend wostream& operator<<(wostream& wout , Flag flag){
            int max = 0;
            for(auto x : flag.vec) max=max<x ? x : max;

            for(int i = max+1 ; i>-1; i--){
                for(auto j : flag.vec){

                    if(i<j) wout<<" "<<vv<<" ";
                    else if(i == j) wout<<sw<<md<<se;
                    else if(i == j+1) wout<<vv<<j<<vv;
                    else wout<<L"　 ";
                }
                wout<<endl;
            }
        	for(auto x : flag.vec) wout<<hh<<mu<<hh;
            return wout;

        }
        
};



int main()
{
    setlocale(LC_ALL, "zh_TW.UTF-8");
    //wcin.imbue(locale(""));
    Flag flag ;
    int n ;
    while ( 1 ) {
    wcout << "> " ;
    wcin >> n ;
    flag.sval(n) ; // 設定旗竿數字
    wcout << flag << endl ; // 印出旗竿
    }

    return 0;
}
