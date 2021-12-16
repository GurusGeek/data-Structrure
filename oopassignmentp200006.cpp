
#include <iostream>
#include <string.h>
using namespace std;

class Basement{
    private:
        int entries;
        bool slots[30];
    
    public:
        int slot(){
            for (int i = 1; i < 31; i++){
                slots[i] = true;
            }
            for (int i = 1; i < 31; i++){
                if (slots[i] == true){
                cout<<"Park at empty slot number B"<<i <<endl;
                slots[i]= false;
                break;
                }
                else
                {
                    cout<<"Parking slot "<<i<<" not empty."<<endl;
                }
                
            }
            return 0;
        }
};

class Ground{
    private:
        int entries;
        bool slots[40];
    
    public:
        int slot(){
            for (int i = 1; i < 41; i++){
                slots[i] == true;
            }
            for (int i = 1; i < 41; i++){
                if (slots[i] == true){
                    cout<<"Park at empty slot number G"<<i<<endl ;
                    break;
                }
                
                else if (slots[i] == false)
                {
                    Basement bc;
                    bc.slot();
                    cout<<"Or ";
                }
                else 
                {
                    cout<<"Sorry No Parking slot not empty."<<endl;
                }
                
            }
            return 0;
        }
};


class Top{
    private:
        int entries;
        bool slots[50];
    
    public:
        int slot(){
            for (int i = 1; i < 51; i++){
                slots[i] == true;
            }
            for (int i = 1; i < 51; i++){
                if (slots[i] == true){
                
                cout<<"Park at empty slot number T"<<i<<endl ;
                break;

                if (slots[i] == false)
                {
                    cout<<"Parking slot "<<i<<" not empty."<<endl;
                }
                break;
                
                }
                
            }
            return 0;
        }
};

class Charges{
    public:
        int charges(int k){
            if (k==1 || k==2 )
            {
                cout<<"Your parking charges are"<< 50<<"rs."<<endl;
            }
            else if (k==3)
            {
                cout<<"Your parking charges are 30rs."<<endl;
            }
            else if (k==4 || k==5 )
            {
                cout<<"Your parking charges are 20rs."<<endl;
            }
            else if (k==6 )
            {
                cout<<"Your parking charges are 10rs."<<endl;
            }
            return 0;
        }
};

class Ticket{
    private:
    int vcharge = 50;
    int ccharge = 40;
    int bcharge = 20;
    int cycharge = 10;
    int xcharge = 0;

    public:
        int Ticket1(string cname)
        {   
            cout<<" The charges according to your vehicle \n";
            if (cname=="van")
            {
                cout<<"Charges are "<<vcharge<<endl;
                xcharge = vcharge;
                return xcharge;
            }
            else if (cname==" car")
            {
                cout<<"Charges are "<<ccharge<<endl;
                xcharge = ccharge;
                return xcharge;
            }
            else if (cname=="bike" || cname=="scooty")
            {
                cout<<"Charges are "<<bcharge<<endl;
                xcharge = vcharge;
                return xcharge;
            }
            else if (cname == "cycle")
            {
                cout<<"Charges are "<<cycharge<<endl;
                xcharge = cycharge;
                return xcharge;
            }
            else
            {
                cout<<"Invalid"<<endl;
            }
        }
    
};

class Salary{
    private:
        int owner;
        int Employess;
    
    public:
        int emp(int w){
            return 0;
        }

};

//below is the superclass
class Parking{
    public:

        Basement b;
        Ground g;
        Top t;

        int vehicleType(int k){
            if (k==1 || k==2 )
            {
                cout<<"Go to Basement."<<endl;
                b.slot();
            }
            else if (k==3)
            {
                cout<<"Go to ground floor."<<endl;
                g.slot();
            }
            else if (k==4 || k==5 || k==6 )
            {
                cout<<"Go to Top floor."<<endl;
                t.slot();
            }
            
            return 0;
        }

    

    Charges m;
    int chr(){ 
        int k;
        m.charges(k);
        return 0;
    }
    
};
class Membership{
    private:
    char yn;
    string yesno;
    public:
    void display(int charg){
        cout<<"Are you having membership\n";
        cin>>yesno;

        if(yesno == "yes"){
            cout<<"Wlecome to our membership scheme\n now you will get half price\n";
            cout<<"Your new charges are now"<<charg/2;
        }
        else if(yesno == "no"){
            cout<<"Would you like to buy membership\n press y for yes n for no";
            cin>>yn;
            if(yn == 'y'){
                cout<<"Please pay amount 1000"<<endl;
                cout<<"Membership activated"<<endl;
            }
            else{
                cout<<""<<endl;
            }
        }
    }
};
class Accomodation{
    private:
        int basement =0;
        int ground=0;
        int floor1= 0;
        
    public:
        Accomodation(string vehicle){
            if(vehicle=="van"){
                if(basement < 30){
                    cout<<"\n\tSpace availabe"<<endl;
                    cout<<"\tPark your vehicle in basement\n";
                }
                else{
                    cout<<"\tSorry no space available \n";
                }
                basement=+1;
                cout<<basement;
            }
            
            if(vehicle=="car"){
                if(ground<40){
                    cout<<"\tSpace availabe"<<endl;
                    cout<<"\tPakr your vehicle on ground floor\n";
                    ground=+1;
                }
                else if(basement<30){
                    cout<<"\tSpace avaiabe at basement\npark your car in basement"<<endl;
                    basement=+1;
                }
                else{
                    cout<<"\tSorry no space availabe \n";
                }

            }
            
            if(vehicle=="bike" || vehicle=="scooty" || vehicle=="cycle"){
                if(floor1 < 50){
                    cout<<"\tSpace availabe\n pakr it on top floor"<<endl;
                    floor1=+1;
                }
                
                else{
                    cout<<"\tSorry no space availabe\n";
                }
            }

        }
};
int main(){
    int Y_N;
    cout<<"ENTER 1 if THERE'S A CAR ENTERING THE PARKING BUILDING ELSE ENTER 0 : ";
    cin>>Y_N;
    //cout<<"\n"<<Y_N;
    while (Y_N <= 51 && Y_N != 0)
    {
        Parking p;
        int v;
        cout<<"For Hi-Aces 1 \nFor Vans Enter 2\nFor car enter 3\nFor Motor-bikes enter 4\nFor Scooters enter 5\nFor Bi-cycle enter 6\nEnter number : ";
        cin>>v;
        int q;
        cout<<"ENTER 2 YOU HAVE PARKING MEMBERSHIP ELSE ENTER 1 : ";
        cin>>q;
        cout<<endl;

        p.vehicleType(v);
        //p.b.slot();
        if (q==2)
        {
            p.n.mcharges(v);
        }
        else if (q==1)
        {
            p.m.charges(v);
        }     

        
        int y_n,W,;
        cout<<"\nENTER 1 if THERE'S A CAR ENTERING THE PARKING BUILDING ELSE ENTER 0 : ";
        cin>>y_n;
  
        if (y_n == 1)
        {
            continue;
        }
          
        if (y_n == 0)
        {
            cout<<"Money generated today = "<<W<<endl;
            cout<<"Todays profit = "<<W-1800<<endl;
            float tax;
            tax = (W-1800)*0.05;
            cout<<"Tax to be paid from todays profit = "<<tax<<endl;
            break;
        }

        return 0;
    } 
}