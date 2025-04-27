#include<iostream>
#include<string>
using namespace std;

class BankAccount{//DEFINING CLASS
   private:  //Private access
        string accountHolder;
        int accountNumber;
        string accountType;
        double balance;
    
    public:   //Public access
        BankAccount()  //Default Constroctor
        {
            accountHolder = "Sejal Krishnaji Shelke";
            accountNumber = 123456;
            accountType = "Saving";
            balance = 5000;
        }

        BankAccount(string Name, int accNo, string accTy, double bal)  //Paramiterized Constructor
        {
            accountHolder = Name;
            accountNumber = accNo;
            accountType = accTy;
            balance = bal;
        }

        //  accessor and mutators
        void getAccountHolder(){
			cout<<"Account Details: "<<endl;
			cout<<"Holder: "<<accountHolder<<endl;
		}
		void getAccountNumber(){
			cout<<"Account Number: "<<accountNumber<<endl;
		}
		
		void getAccountType(){
			cout<<"Type: "<<accountType<<endl;
		}
		
		void getBalance(){
			cout<<"Balance: "<<balance<<endl<<endl;
		}

        void setInfo(string type){
            accountType = type;
        }

        //methods
        void deposit(double amount){
            if(amount > 0)
               balance += amount;
            
            cout<<"\nDepositing: "<<amount<<endl;
            cout<<"New Balance: "<<balance<<endl;
            cout<<'\n';
        }

        void withdraw(double amount){
            if(amount > 0 && amount < balance)
               balance -= amount;
            
            cout<<"\nWithdrawing: "<<amount<<endl;
            cout<<"New Balance: "<<balance<<endl;
            cout<<'\n';
        }

        void displayAccountDetails()
        {
            cout<< "Updated Account Details: "<<endl;
            cout<< "Holder: "<<accountHolder<<endl;
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Type: "<<accountType<<endl;
            cout<<"Balance: "<<balance<<endl;
            cout<<'\n';
        }
};

int main()
{
    BankAccount b1;  // b1 object 
    b1.getAccountHolder();
    b1.getAccountNumber();
    b1.getAccountType();
    b1.getBalance();
    b1.deposit(2000);
    b1.withdraw(1500);
    b1.displayAccountDetails();

    string accHolder,accType;
	int accNumber;
	double accBalance;
	double money_depo,money_withd;
	cout<<"Enter Account holder name: "<<endl;
	cin>>accHolder;
	cout<<"Enter Accountnumber: "<<endl;
	cin>>accNumber;
	cout<<"Enter Account type: "<<endl;
	cin>>accType;
	cout<<"Enter Balance: "<<endl;
	cin>>accBalance;
	cout<<"Enter cash amount to deposit "<<endl;
	cin>>money_depo;
	cout<<"Enter cash amount to withdraw: "<<endl;
	cin>>money_withd;
	BankAccount b2(accHolder, accNumber, accType, accBalance);  // b2 object
	b2.deposit(money_depo);
	b2.withdraw(money_withd);
	b2.displayAccountDetails();
    
    return 0;
}