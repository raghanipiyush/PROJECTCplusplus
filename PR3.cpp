#include <iostream>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    char manufacturer[20];
    char model[20];
    int year;

public:
    static int totalVehicles;

    Vehicle(){
	    vehicleID = 0;
        year = 0;
        totalVehicles++;
    }

    ~Vehicle() {}
	void setData(){
      cout << "Enter ID: ";
        cin >> vehicleID;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
    }

    int getID(){
	    return vehicleID;
    }

    void display(){
        cout << "\nID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
public:
    char fuelType[20];
};

class ElectricCar : public Car
{
public:
    int batteryCapacity;
};

class SportsCar : public ElectricCar
{
public:
    int topSpeed;
};

class Sedan : public Car
{
};

class SUV : public Car
{
};

class Aircraft
{
public:
    int flightRange;
};

class FlyingCar : public Car, public Aircraft
{
};

class VehicleRegistry{
    Vehicle v[10];
    int count;

public:
    VehicleRegistry(){
	    count = 0;
    }

    void addVehicle(){
	    if (count < 10){
		    v[count].setData();
            count++;
        }
        else{
		    cout << "Registry Full!\n";
        }
    }
       void displayVehicles(){
	    for (int i = 0; i < count; i++){
		    v[i].display();
        }
    }
       void searchVehicle(int id){
	    for (int i = 0; i < count; i++){
		    if (v[i].getID() == id){
			    v[i].display();
                return;
            }
        }
        cout << "Vehicle Not Found!\n";
    }
};

int main(){
    VehicleRegistry vr;
    int choice, id;

    do{
	    cout << "\n----- Vehicle Registry -----";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search By ID";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            vr.addVehicle();
            break;
        case 2:
            vr.displayVehicles();
            break;
         case 3:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            vr.searchVehicle(id);
            break;
         case 4:
            cout << "Exit...";
            break;
         default:
            cout << "Invalid Choice!";
        }
   } while (choice != 4);
}
/*output

----- Vehicle Registry -----
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Enter Choice: 1
Enter ID: 101
Enter Manufacturer: mahindra
Enter Model: scorpio
Enter Year: 2010

----- Vehicle Registry -----
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Enter Choice: 1
Enter ID: 102
Enter Manufacturer: hyundai
Enter Model: creta
Enter Year: 2015

----- Vehicle Registry -----
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Enter Choice: 1
Enter ID: 103
Enter Manufacturer: toyota
Enter Model: hyryder
Enter Year: 2020

----- Vehicle Registry -----
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Enter Choice: 3
Enter Vehicle ID: 103

ID: 103
Manufacturer: toyota
Model: hyryder
Year: 2020

----- Vehicle Registry -----
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Enter Choice: 2

ID: 101
Manufacturer: mahindra
Model: scorpio
Year: 2010

ID: 102
Manufacturer: hyundai
Model: creta
Year: 2015

ID: 103
Manufacturer: toyota
Model: hyryder
Year: 2020

----- Vehicle Registry -----
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Enter Choice: 4
Exit...
*/