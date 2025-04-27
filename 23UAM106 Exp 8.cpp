#include <iostream>
using namespace std;

template <typename T>
T findMax(T a, T b)
{
    return (a > b) ? a : b;
}
template <typename T>
class Calculator{
private:
     T num1;
     T num2;
    
public:
     Calculator(T n1, T n2)
     {
      num1 = n1;
      num2 = n2;
     }
        
     T addNum(){
         return num1 + num2;
      }
        
     T subNum(){
         return num1 - num2;
     }
        
     T multiplyNum(){
          return num1 * num2;
      }
        
     T divideNum(){
           if(num2 != 0)
                return num1 / num2;
           else
                return -1;
      }
};

int main() {
    int a = 7, b = 4;
    float c = 5.0, d = 8.9;
    double e = 8.0, f = 9.30;
    Calculator<int> c1(a,b);
    cout <<"Max between "<<a<<" and "<<b<<" is "<< findMax(a,b) << endl;
    cout<<"Addition is "<<c1.addNum()<<endl;
    cout<<"subtraction is "<<c1.subNum()<<endl;
    cout<<"Multiplication is "<<c1.multiplyNum()<<endl;
    cout<<"Division is "<<c1.divideNum()<<endl;
    
    Calculator<float> c2(c,d);
    cout <<"\nMax between "<<c<<" and "<<d<<" is "<< findMax(c,d) << endl;
    cout<<"Addition is "<<c2.addNum()<<endl;
    cout<<"subtraction is "<<c2.subNum()<<endl;
    cout<<"Multiplication is "<<c2.multiplyNum()<<endl;
    cout<<"Division is "<<c2.divideNum()<<endl;
    
    Calculator<double> c3(e,f);
    cout <<"\nMax between "<<e<<" and "<<f<<" is "<< findMax(e,f) << endl;
    cout<<"Addition is "<<c3.addNum()<<endl;
    cout<<"subtraction is "<<c3.subNum()<<endl;
    cout<<"Multiplication is "<<c3.multiplyNum()<<endl;
    cout<<"Division is "<<c3.divideNum()<<endl;
    
    

    return 0;
}