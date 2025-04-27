#include<iostream> 
#include<iomanip> 
using namespace std; 
int main() 
{ 
string str="Welcome to bank"<<endl; 
Int ch,n=0,number,i=0,j=0, 
Int flag=0; 
int arr_deposit[5]={0}; 
int arr_withdrawl[5]={0}; 
cout<<setw(25)<<str<<endl; 
int bank_balance=10000; 
do { 
cout<<"1.Deposite the amount\t 2.Withdrawal the amount\t 3.Mini 
statement"<<endl; 
cout<<"Enter your choice"; 
cin>>ch; 
switch(ch){  
case 1: cout<<"current bank         
"<<bank_balance<<endl; 
int deposite; 
balance is: 
cout<<"Enter deposite amount : "; 
cin>>deposite; 
arr_deposit[i]=deposite; 
i++; 
bank_balance=bank_balance+deposite; 
cout<<"successfully deposited ! current bank balance is: "<<bank_balance<<endl; 
break; 
case 2: cout<<"current bank balance is: "<<bank_balance<<endl; 
int withdrawl; 
cout<<"Enter withdrawl amount : "; 
cin>>withdrawl; 
arr_withdrawl[j]=withdrawl; 
j++; 
bank_balance=bank_balance-withdrawl; 
cout<<"successfully withdrawl ! current bank balance is: "<<bank_balance<<endl; 
break; 
case 3:  
i=0,j=0; 
while(arr_deposit[i]!=0) 
{ 
cout<<"+"<<arr_deposit[i]<<"\n"; 
i++; 
} 
while(arr_withdrawl[j]!=0){ 
cout<<"-"<< 
arr_withdrawl[j]<<"\n"; 
j++; 
break; 
} 
default: cout<<"please enter correct choice"; 
break;} 
n++; 
}while(n<5); 
} 