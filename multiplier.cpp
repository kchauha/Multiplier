#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include "iostream"
#include <sstream>
#include <bitset>
#include <math.h>

using namespace std;
class operate
{
    public:
        int size,reg;
        vector<int> v,u;      
        void set_val(vector<int>,vector<int>, int);
        void shift_left( void);
        void shift_right(void);
        int  add_result();
        void Multiplier(int, int);
	vector<int> vectorMultiplier(vector<int> first,vector<int> second);
        int  toDecimal(vector<int>);
        vector<int> toBinary(int);
        char getHexCharacter(std::string );
        std::string getHexRowFails(string );
        void print_val(int);
	vector<int> shiftPad_vector(vector<int> x,int r,int v);
	int tempDecimal(vector<int> A);
	vector<int> pad(vector<int> A,int S);
	int tempToDecimal(vector<int> A);

        

};
//-------------------vector multiply--------------------------//

vector<int> operate:: vectorMultiplier(vector<int> first,vector<int> second)
{
operate o;
int i;
int prd = 0,productReg = 0;
vector<int> mul;
int as;
for(int x=0;x<second.size();x++)
{
int a = o.tempDecimal(first);
int b = o.tempDecimal(second);
int bs = second.size();
as = first.size();
i = second.at(bs-1);
if(i==1)
{
prd = prd + a;
productReg=prd;
}
second = o.shiftPad_vector(second,1,0);
first = o.shiftPad_vector(first,-1,0);
//shift_left();
//shift_right();
	
}
mul = o.toBinary(productReg);
mul = o.pad(mul,as);
return mul;
}

//-------------------Shift with padding--------------------------//


vector<int> operate:: shiftPad_vector(vector<int> x,int r,int v)
{
if(r>=0)
{
rotate(x.rbegin(),x.rbegin()+r,x.rend());
for (int i=0;i<r;i++)    x[i]=v;
}
else
{
rotate(x.begin(),x.begin()+(-r),x.end());
for (int i=(x.size()-1);i>=(x.size()+r);i--)    x[i]=v;
}
return x;
}

vector<int> operate:: pad(vector<int> A,int S)
{
int x=(S-A.size());
for (int i=0;i<x;i++)    A.insert(A.begin(),0);
return A;
}


//-------------------decimal to binary--------------------------//

vector<int> operate:: toBinary( int k)
{
vector<int> h;
  
while(k>0)
{
    h.push_back(k%2);
    k=k/2;
}
reverse(h.begin(),h.end());
return h;
}


//--------------------print-------------------------------------//
  void operate :: print_val(int d)
{
	operate o;           
	string n;
             //cout<<"Multiplication=="<<reg<<endl;
             //vector<int> s= toBinary(reg);

             //bitset<16> b=reg;
             //s.resize(size);
	
		vector<int> s=vectorMultiplier(v,u);
	
	if((s.size()-2*size)>0){
	int o = s.size()-2*size;
	s.erase (s.begin(),s.begin()+o);}
	for(int i=0;i< s.size();i++)
            {
             cout<<s[i];
            }
	if(d==1){
             cout<<"("<<o.tempToDecimal(s)<<")";
            cout<<endl;
    		}
	else	cout<<endl;
	//mul_vector();
               bitset<16> bs=reg;
               string h=bs.to_string();
               //cout<<"SUM="<<h<<endl;       
               n= getHexRowFails(h); 
               //cout<<endl<<"(0x"<<n<<")";


}
//---------------------to Hex--------------------------------------------
char operate ::getHexCharacter(std::string str)
{
	if(str.compare("1111") == 0) return 'F';
	else if(str.compare("1110") == 0) return 'E';
	else if(str.compare("1101")== 0) return 'D';
	else if(str.compare("1100")== 0) return 'C';
	else if(str.compare("1011")== 0) return 'B';
	else if(str.compare("1010")== 0) return 'A';
	else if(str.compare("1001")== 0) return '9';
	else if(str.compare("1000")== 0) return '8';
	else if(str.compare("0111")== 0) return '7';
	else if(str.compare("0110")== 0) return '6';
	else if(str.compare("0101")== 0) return '5';
	else if(str.compare("0100")== 0) return '4';
	else if(str.compare("0011")== 0) return '3';
	else if(str.compare("0010")== 0) return '2';
	else if(str.compare("0001")== 0) return '1';
	else if(str.compare("0000")== 0) return '0';
	else if(str.compare("111")== 0) return '7';
	else if(str.compare("110")== 0) return '6';
	else if(str.compare("101")== 0) return '5';
	else if(str.compare("100")== 0) return '4';
	else if(str.compare("011")== 0) return '3';
	else if(str.compare("010")== 0) return '2';
	else if(str.compare("001")== 0) return '1';
	else if(str.compare("000")== 0) return '0';
	else if(str.compare("11")== 0) return '3';
	else if(str.compare("10")== 0) return '2';
	else if(str.compare("01")== 0) return '1';
	else if(str.compare("00")== 0) return '0';
	else if(str.compare("1")== 0) return '1';
	else if(str.compare("0")== 0) return '0';
}

std::string operate ::getHexRowFails(string rowresult)
{
	std::string endresult = "";
	for(int i = 0; i < rowresult.length(); i = i+4)
	{
		endresult += getHexCharacter(rowresult.substr(i,4));
	}
	return endresult;
}


//----------------------initialization---------------------------//
    void operate:: set_val( vector<int> q, vector<int> p, int s)
{
     v=q;
     u=p;
     size=s;
   
}
//----------------------left shift-----------------------------//
    void operate:: shift_left(void)
{
            rotate(v.begin(), v.begin()+1, v.end());                
	    v[size-1]=0;
           // for(int i=0 ;i<size; i++)
                       // cout<<v[i];
                   //cout<<endl;
            
}
//---------------------right shift----------------------------//
    void operate:: shift_right(void)
{
            rotate(u.rbegin(),u.rbegin()+1, u.rend());
            u[0]=0; 
}

//----------------toDecimal----------------------------------//

int operate :: toDecimal(vector<int> t)
{
    

 long int k=0, dec=0, base=1;
  for(int i=0; i<t.size()-1;i++)
  	{
		dec+= t[i] * pow(2,k) ;
		k++;
	}
   //cout<<dec;//int m= t.size()-1;
     dec=dec-t[k]* pow(2,k);
    //cout<<dec<<endl;
   return(dec);
}

int operate:: tempToDecimal(vector<int> A)
{
int sum=0,x=1;
for (int i=A.size()-1;i>=0;i--)
{
    sum=sum+A[i]*x;
    x=x*2;
}
return sum;
}


int operate:: tempDecimal(vector<int> A)
{
int sum=0,x=1;
for (int i=A.size()-1;i>=0;i--)
{
    sum=sum+A[i]*x;
    x=x*2;
}
return sum;
}

//-----------------Multiplier---------------------------//

   void operate :: Multiplier(int a, int b)
{
    int temp=0,n,count=32;
       int len= 2*size-v.size();
    //cout<<v[0]<<endl;
      if(v[0]==0)
        {
           for(int i=0;i<len;i++)
            v.insert(v.begin(),0);
         int newS=size+size;
        //for(int i=0;i<newS; i++)
             //cout<<v[i];          
             //cout<<endl;
        }
       if(v[0]==1)
        {
           for(int i=0;i<len;i++)
            v.insert(v.begin(),1);
         int newS=size+size;
       // for(int i=0;i<newS; i++)
             //cout<<v[i];          
             //cout<<endl;
        }


/*             
         while(count>0)
         {
             if(u[size-1]==0)
            {
             shift_left();
             shift_right();    
            }
             if(u[size-1]==1)
             {
              
              n= toDecimal(v);   
               cout<<n<<endl;                                   
              temp=temp + n;
              shift_left();
             shift_right();   
             }
           count--;
            }
     if((a==1)||(b==1))
          reg=temp * (-1);         
     if(((a==1)&&(b==1))||((a==0) && (b==0)))
          reg=temp; 

*/
}


int main(int argc, char *argv[]) {
    int opt= 0,n;    
    int vec=-1, size, vec1=-1, mul=0, dh=-1;
    operate obj;
    vector<int> v,u;
    string s,t;
    stringstream ss;
   
      
    static struct option long_options[] = {
        {"vec",    required_argument,   NULL,  'i' },
        {"size",   required_argument,   NULL,  's' },
        {"vec1",   required_argument,   NULL,  'I' },
        {"mul",    required_argument,      0,  'o' },
        {"deci",     no_argument,          0,  'd' }, 
        {"hex",     no_argument,           0,  'h' },    
        {"print",  no_argument,            0,  'p' },
        {0,           0,                   0,   0  }
    };

     int long_index =0;            
     int i=0, neg=0, neg1=0;
     int print =0;
     unsigned int x;
     while ((opt = getopt_long(argc, argv,"i:s:I:o:d:h:p",long_options, &long_index)) != -1) {
        switch (opt) {
             case 'i' : 
                       s=optarg;
                           vec=atoi(optarg);
                       break;
             case 's' : size=atoi(optarg);                     
                      break;
             case 'I' : s=optarg;     
                           vec1=atoi(optarg);
                       break;            
             case 'o' : mul=1;                        
                 break;
             
             case 'd' : dh= 1;
                 break;
             case 'h' : dh= 0;
                  break;
             case 'p' :  print=1;                 
                 break;
             default: //print_usage(); 
                 exit(EXIT_FAILURE);
  
        }
    }
   // cout<<dh<<endl;
//-------------------Vector1 initialization-------------- 
       if(vec>=0)
     {
         
          for(int j=0;j<size;j++)
     {
          int n= vec% 10;
          if((n!=0) && (n!=1)) 
          {
                cerr<<"Invalid Syntax"<< endl;
                return -1;
          }             
                v.push_back(n);
                vec=vec/10;
     }
       
                reverse(v.begin(), v.end()); 
               // for(int i=0 ;i<size; i++)
                      //  cout<<v[i];
                cout<<endl;
     }
         
       else
     {
      cerr<<"Invalid Syntax"<< endl;
       return -1;
     }
    

//----------------Vector2 initialization-------------------------------

      if(vec1>=0)
     {
          for(int j=0;j<size;j++)
     {
          int n= vec1% 10;
          if((n!=0) && (n!=1)) 
          {
                cerr<<"Invalid Syntax"<< endl;
                return -1;
          }             
                u.push_back(n);
                vec1=vec1/10;
     }
       
                reverse(u.begin(), u.end()); 
     }
       else
     {
       cerr<<"Invalid Syntax"<< endl;
       return -1;
     }
     
  //-------------------------------------------------------------------------- 

           obj.set_val(v, u,size);
	   obj.Multiplier(neg,neg1);
           // cout<<print;
	    //cout<<"print"<<print<<"dh"<<dh;    
//    if(print==1)
           obj.print_val( dh);



}
