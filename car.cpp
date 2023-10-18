// Bahaar Ahuja - 4055554
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>

Car::Car() : manufacturer(nullptr), model(nullptr), zeroToSixtyNs(0), headonDragCoeff(0), horsepower(0), backseatDoors(None), seatCount(0) {}


Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
    manufacturer = strdup(manufacturerName);
    model = strdup(modelName);
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    seatCount = numSeats;
    backseatDoors = backseatDoorDesign;
}

Car::Car(const Car& o) {
    manufacturer = strdup(o.manufacturer);
    model = strdup(o.model);
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    seatCount = o.seatCount;
    backseatDoors = o.backseatDoors;
}//constr\uctor not same as default constructor

Car::~Car() {
        delete[] manufacturer;

        delete[] model;

}//  destructor 

Car& Car::operator=(const Car& o) {
    if (this == &o) {
        return *this;
    }

    delete[] manufacturer;
    delete[] model;

    manufacturer = strdup(o.manufacturer);
    model = strdup(o.model);
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    seatCount = o.seatCount;
    backseatDoors = o.backseatDoors;

    return *this;
}


char const* Car::getManufacturer() const { 
    return manufacturer;
     }

char const* Car::getModel() const { 
    return model; 
    }

PerformanceStats Car::getStats() const {
    PerformanceStats perf = {horsepower, zeroToSixtyNs, headonDragCoeff};
    return perf;

}

uint8_t Car::getSeatCount() const { 
    return seatCount; 
    }

DoorKind Car::getBackseatDoors() const { 
    return backseatDoors; 
}

void Car::manufacturerChange(char const* const newManufacturer){
    delete[] manufacturer; 
    manufacturer = strdup(newManufacturer);
}

void Car::modelNameChange(char const* const newModelName){
delete[] model;      
model = strdup(newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats){
 zeroToSixtyNs = newStats.zeroToSixtyNs;
 headonDragCoeff = newStats.headonDragCoeff;
 horsepower = newStats.horsepower;
 }

void Car::recountSeats(uint8_t newSeatCount){
seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind){
    backseatDoors = newDoorKind;
    }
