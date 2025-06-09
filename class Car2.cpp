#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Car {
    private:
        string brand;
        int year;
    public:
        Car()
        {
            brand="\0";
            year=1300;
        }
        Car(string Br="207",int Y=1390){
            brand=Br;
            year=Y;
        }
        Car(const Car & Other){
            brand=Other.brand;
            year=Other.year;
        }
        void displayInfo() {
            cout << "Brand: " << brand << ", Year: " << year << endl;
        }
        void SetBrand(string b)
        {
            brand=b;
        }
        void SetYear(int y)
        {
            year=y;
        }
        string getBrand()
        {
            return brand;
        }
        int getYear()
        {
            return year;
        }
        bool operator ==(const Car & Other)
        {
            if(brand==Other.brand && year==Other.year)
                return true;
            else
                return false;
        }
        Car operator +(const Car & Other)
        {
            Car Result("hghg",2010);
            Result.brand=brand+Other.brand;
            Result.year=year>Other.year?year:Other.year;
            return Result;
        }
        Car& operator =(const Car & Other)
        {
            this->brand=Other.brand;
            this->year=Other.year;
            return *this;
        }
        ~Car()
        {
            cout<<"This Object with brand "<<brand<<" deleted"<<endl;
        }
};
int main() {
    Car myCar("Saipa",2022);//Parameter Constructor
    Car RaienMotor("Raien");

    if(myCar==RaienMotor)
        cout<<"\n Equal\n";
    else
        cout<<"\n Not Equal\n";

    Car ShirazMotor("kjkj",2013);
    Car CarCopy(myCar);
    //(myCar+RaienMotor).displayInfo();
    CarCopy=ShirazMotor=myCar+RaienMotor;
    cout<<"Info of ShirazMotor: ";
    ShirazMotor.displayInfo();
    cout<<"Info of CarCopy: ";
    CarCopy.displayInfo();



    /*Car ShirazMotor("\0",1404);
    Car CarCopy(myCar);//Copy Constructor
    CarCopy.SetBrand("Samand");
    Car Car2=myCar;//Copy Constructor
    Car2.SetYear(2025);
    Car2.SetBrand("Toyota");
    Car2.SetBrand(myCar.getBrand());
    myCar.displayInfo();
    CarCopy.displayInfo();
    Car2.displayInfo();
    RaienMotor.displayInfo();
    ShirazMotor.displayInfo();
    //cout<<Car2.getBrand()<<endl;*/
    return 0;
}
