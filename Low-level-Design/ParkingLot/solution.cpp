/*
Parking lot system
*/

/* 
Entities :

class ParkingLotSystem (Singleton)

class ParkingLot
    vector<vector<Slot>> spaces; // 0 or 1

class Vehicle

class Car

class Bus

class Ticket
    int startTime;
    int endTime;
    int pricePerMinute;
    int vehicleId;

class Slot

class 2DParkingSlot : public Slot
    int length;
    int width;    
*/

#include <iostream>
#include <string>


int getSystemTime()
{
    return 23234;
}

class ParkingLotSystem
{
    // Parking Lot full 
    // Vehicle in
    // Vehicle out

    public:        

        static ParkingLotSystem& getInstance()
        {
            static ParkingLotSystem instance;
            return instance;
        }   
        
        ParkingLotSystem(ParkingLotSystem &) = delete;
        ParkingLotSystem& operator=(ParkingLotSystem &) = delete;


    private:
        ParkingLotSystem()
        {
        }

        void vehicleIn(std::string type, unsigned int id)
        {
            std::shared_ptr<Vehicle> vehicle = registerVehicle(type);            
            if (parkedIds.find(id) != parkedIds.empty())
            {
                std::cout << "Vehicle already parked.";
                return;
            }

            Ticket newTicket = Ticket(getTime(), VEHICLE_RATE); // Modify this based on vehicle type

            vehicle.setId(id);
            vehicle.(getTime());
        }

        std::shared_ptr<Vehicle> registerVehicle(std::string vehicleType)
        {
            std::shared_ptr<Vehicle> vehicle;
            
            if (vehicleType == "Car")
            {
                vehicle = std::make_shared<Car>(Car());    
            }
            
            else if (vehicleType == "Bus")
            {
                vehicle = std::make_shared<Bus>(Bus());    
            }
            
            else
            {
                std::cout <<"Invalid Vehicle type";
            }

            return vehicle;
        }

        std::set<int> parkedIds;
        int VEHICLE_RATE;
};