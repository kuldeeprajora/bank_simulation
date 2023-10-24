#include<iostream>
#include<string>
using namespace std;
const int maxacc= 12;

class accounts{
private:
int acc_no;
string acc_name;
double balance;
public:

accounts():acc_no(0),acc_name(""),balance(0){}
void openacc(int accnum , const string &accname){
    acc_no = accnum;
    acc_name = accname;
    balance = 0;
    cout<<"Account created"<<endl;

}

void deposit(double amount){
    if(amount > 0){
        balance += amount;
        cout<<"Deposited : RS "<<amount<<endl;
    }
    else{
        cout<<"Deposit valid amount"<<endl;

    }
}
void withdraw(double amount){
    if(amount > balance &&  amount <= balance){
        balance -= amount ;
        cout<<"Balance : Rs "<<amount<<endl;
    }
    else{
        cout<<"Insuffecient Balance "<<endl;
    
    }

}
void acc_details(){
cout<<"Account no. : "<<acc_no<<endl;
cout<<"Account Holder's Name : "<<acc_name<<endl;
cout<<"Account Balance :RS "<<balance<<endl;

}
};
int main(){

accounts acc[maxacc];
int acc_no =1;
char choice;
while(true){
    cout << "Bank Simulation Menu:" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
switch (choice)
{
case '1':{
    if (acc_no <= maxacc){
        string name;
        cout<<"Enter Acc holder's Name"<<endl;
        cin>>name;
        acc[acc_no - 1].openacc(acc_no,name);
        acc_no++;
    }
else{
    cout<<"Max acc reached"<<endl;
}

    break;
}
case '2':{
   int accnum;
   double amount;
   cout<<"Enter account no"<<endl;
   cin>>accnum;
   cout<<"Enter the deposit amount : Rs "<<endl;
   cin>>amount;
   if(accnum > 0 && accnum< maxacc){
    acc[accnum - 1].deposit(amount);
   }  
else{
    cout<<"enter valid acc no"<<endl;
}
break;
}
case '3':{
     int accnum;
   double amount;
   cout<<"Enter account no"<<endl;
   cin>>accnum;
   cout<<"Enter the withdrawl amount : Rs "<<endl;
   cin>>amount;
   if(accnum > 0 && accnum< maxacc){
    acc[accnum - 1].withdraw(amount);
   }  
else{
    cout<<"enter valid acc no"<<endl;
}
break;
}
case '4':{
 int accnum;
  
   cout<<"Enter account no"<<endl;
   cin>>accnum;
  
   if(accnum > 0 && accnum< maxacc){
    acc[accnum - 1].acc_details();

   }  
else{
    cout<<"enter valid acc no"<<endl;
}
break;
}
case '5' :{
    return 0;
}
default: {cout<<"Enter valid choice"<<endl;}

}
}
return 0;
}