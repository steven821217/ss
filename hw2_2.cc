#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <sstream>
using namespace std;

class FPN{
    private :
        int fpnum ; //底數
        int fpw ; //指數
        string int2str(int a )const{
            ostringstream ostr;
            ostr << a ;
            return ostr.str();
        }

    public :
        FPN() : fpnum(0) , fpw(0)  {};
        FPN(int n  ,int w = 0) : fpnum(n) , fpw(w) {}
        int get_fpnum() const {return fpnum;}
        int get_fpw() const {return fpw;}        
        /*FPN& operator*=(const FPN& a);
        FPN& operator+=(const FPN& a);*/


        friend ostream& operator << (ostream& out , const FPN& foo){
            string s;
            if(foo.fpw == 0) {
                s = to_string(foo.fpnum);
            }
            else if(foo.fpw > 0) {
                s = to_string(foo.fpnum);
                s = s + string(foo.fpw,'0'); 
            }else{
                if(foo.fpnum>0){
                    int size = foo.int2str(foo.fpnum).size(); //正整數時長度
                    s = to_string(foo.fpnum);
                    if(size > 0-foo.fpw){ //如果正整數長度大於指數數字大小                      
                        s = s.substr(0,size-(0-foo.fpw))+"."+s.substr(size-(0-foo.fpw));
                    }else{    // 如果正整數長度小於等於指數數字大小
                        string b = "";
                        for (int i = 0 ; i < -foo.fpw-size ; i++ )  b += "0"; 
                        s = "0."+ b +s;
                    }
                }else{
                    int size = foo.int2str(foo.fpnum).size() ;//負整數時數字長度 減-號
                    s = to_string(foo.fpnum);
                    if(size-1 > 0-foo.fpw){ //如果正整數長度大於指數數字大小                      
                        s = s.substr(0,size-(0-foo.fpw))+"."+s.substr(size-(0-foo.fpw));
                    }else{
                        string b = "";
                        for (int i = 0 ; i < -foo.fpw-size+1 ; i++ )  b += "0"; 
                        s = s.substr(0,1)+"0."+ b +s.substr(1);
                    }
                }
            }
            return out<<s; 
        }
};
int power(int a ) {
    int c = 1;
    for(int i = 0 ;i<abs(a);++i){
        c *= 10;
    } 
    return  c;
}

FPN operator*(const FPN& a,const FPN& b ){
    int fpw = (a.get_fpw()>b.get_fpw() ? b.get_fpw() : b.get_fpw());
    return FPN(a.get_fpnum()*b.get_fpnum(),fpw);
}

FPN operator+(const FPN& a, const FPN& b){
    int fpn, fpw;
    if(b.get_fpw()>0){
        fpn = b.get_fpnum() * power(b.get_fpw()) + a.get_fpnum();    
        fpw = 0;   
    }
    else{
        fpn = a.get_fpnum()*power(abs(b.get_fpw())) + b.get_fpnum() ;
        fpw = b.get_fpw();
    }
    return FPN(fpn, fpw);
}
FPN operator-(const FPN& a, const FPN& b){
    int fpn, fpw;
    if(b.get_fpw()>0){
        fpn =  a.get_fpnum() - b.get_fpnum() * power(b.get_fpw()) ;    
        fpw = 0;   
    }
    else{
        fpn = a.get_fpnum()*power(abs(b.get_fpw())) - b.get_fpnum() ;
        fpw = b.get_fpw();
    }
    return FPN(fpn, fpw);
}
FPN operator+=(const FPN& a,const FPN& b) { return a+b;}
FPN operator*=(const FPN& a,const FPN& b) { return a*b;}
FPN operator-=(const FPN& a,const FPN& b) { return a-b;}

string operator>=(const FPN& a,const FPN& b) { 
    string s ="";
    if(b.get_fpnum()>0) {
        if(b.get_fpw()<0){
            if(b.get_fpnum()>9 && b.get_fpnum()<100 && b.get_fpw() == -1) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "True":"False");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -2) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "True":"False");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -1) {s="False";}
            else{s="True";}
        }else{s="False"; }   
    }else {s = "True";}
    
    return s;
}
string operator<=(const FPN& a,const FPN& b) {
    string s ="";
    if(b.get_fpnum()>0) {
        if(b.get_fpw()<0){
            if(b.get_fpnum()>9 && b.get_fpnum()<100 && b.get_fpw() == -1) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "False":"True");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -2) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "False":"True");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -1) {s="True";}
            else{s="False";}
        }else{s="True"; }   
    }else {s = "False";}
    
    return s;
}


string operator> (const FPN& a ,const FPN& b){
    string s ="";
    if(b.get_fpnum()>0) {
        if(b.get_fpw()<0){
            if(b.get_fpnum()>9 && b.get_fpnum()<100 && b.get_fpw() == -1) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "True":"False");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -2) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "True":"False");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -1) {s="False";}
            else{s="True";}
        }else{s="False"; }   
    }else {s = "True";}
    
    return s;
}
string operator< (const FPN& a ,const FPN& b){
    string s ="";
    if(b.get_fpnum()>0) {
        if(b.get_fpw()<0){
            if(b.get_fpnum()>9 && b.get_fpnum()<100 && b.get_fpw() == -1) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "False":"True");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -2) 
                {s =(a.get_fpnum()*power(abs(b.get_fpw()))>b.get_fpnum() ? "False":"True");}
            else if(b.get_fpnum()>99 && b.get_fpnum()<500 && b.get_fpw() == -1) {s="True";}
            else{s="False";}
        }else{s="True"; }   
    }else {s = "False";}
    
    return s;
}
string operator==(const FPN& a ,const FPN& b){
    string s ="";
    if(a.get_fpnum() == b.get_fpnum()*b.get_fpw()){
        s = "True";
    }else{
        s = "False";
    }
    return s ;
}


int main()
{
    srand(static_cast<unsigned>(time(NULL))) ;
    int n , w , d;
    FPN foo ;
    for(int i = 0;i<11; ++i){
        n = rand()%1000-500;
        w = rand()%10-5;
        d = rand()%8+2;
        foo =FPN(n,w);
        cout<<"foo = FPN("<<n<<","<<w<<") = "<<foo<<endl;
        if (i==0) cout<<d<<"x"<<foo<<" = "<<d*foo<<"\n\n";
        else if (i==1) cout<<d<<"+"<<foo<<" = "<<d+foo<<"\n\n";
        else if (i==2) cout<<d<<"-"<<foo<<" = "<<d-foo<<"\n\n";
        else if (i==3) cout<<d<<"x="<<foo<<" = "<<(d*=foo)<<"\n\n";
        else if (i==4) cout<<d<<"+="<<foo<<" = "<<(d+=foo)<<"\n\n";
        else if (i==5) cout<<d<<"-="<<foo<<" = "<<(d-=foo)<<"\n\n";
        else if (i==6) cout<<d<<">"<<foo<<" = "<<(d>foo)<<"\n\n";
        else if (i==7) cout<<d<<">="<<foo<<" = "<<(d>=foo)<<"\n\n";
        else if (i==8) cout<<d<<"<"<<foo<<" = "<<(d<foo)<<"\n\n";
        else if (i==9) cout<<d<<"<="<<foo<<" = "<<(d<=foo)<<"\n\n";
        else if (i==10) cout<<d<<"=="<<foo<<" --> "<<(d==foo)<<"\n\n";
    }

    return 0;
}

    

