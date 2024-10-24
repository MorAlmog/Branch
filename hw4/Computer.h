//Student Mor Almog, gm.bebel12@gmail.com 307850792
#pragma once

#ifndef COMPUTER_H
#define COMPUTER_H

class PeripheralDevice;
class Item;

#include "Item.h"
#include "PeripheralDevice.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include "HWExceptions.h"

using std::vector;


/*class Computer documentation:
    a derivitive class of the virtual class - Item.

    private members:
        id:                         inherited
        price:                      inherited
        manufacturer:               inherited
        cpu:                        string which holds the name of the cpu
        is_a_laptop:                bool type; true = laptop, false - PC/desktop
        usb:                        int type, can not be changed after first initialisation 
        connected_devices:          vector which can hold pointers to PeripheralDevices and saved the devices connected to the computer
        check_if_connected:         a utility array of type bool - is used as an indicator to whether or not a type of device is currently 
                                    connected to the computer
    methods:
        print_connected:            prints all devices connected to the computer

    operator overloading:
        std::string():              syntax: std::string(Computer** computer),
                                    returns a string with all private members of the object in the following order:  id <num>: <manufacturer>, <price>$, <is_a_laptop>, <cpu> 
                                    uses the virtual operator overloading of Item, then adds its own private members to the string.
        assignment operator:        syntax: lhs_computer = rhs_computer;
    
    private (utility) methods:
        usb_oneTimeSetter:          a setter which allows the user to set the amount od usb ports once, and then keeps this field constant
*/

class Computer : public Item /*public Observer*/ {
    //id                            //members inherited privately from Item, can be accessed using corresponding getters and setters
    //price
    //manufacturer
    std::string cpu;
    bool is_a_laptop;
    int usb;
    vector<PeripheralDevice*> connected_devices; //= vector<PeripheralDevice*>(0);
    bool check_if_connected[PDEVICE_TYPES_NUM] = { false };

public:

    //getters
    std::string getCpu() const { return cpu; }
    bool getIsALaptop() const { return is_a_laptop; }
    int getPort() const { return usb; }

    //getters which return pointers to vector
    vector<PeripheralDevice*>& getConnectedDevices() { return connected_devices; }  //trying to add const to signature does not compile (why tho?)
                                                                                    //vector<PeripheralDevice*>& getConnectedDevices() const{}
    bool* getCheckIfConnected() { return check_if_connected; }

    //setters
    void setCpu(const std::string& cpu);
    void setIsALaptop(const bool& is_a_laptop);
    void setPort(const int& usb);

    //operator std::string()
    //returns a string of all private members of object
    operator std::string() const;

    //assignment operator=
    Computer& operator=(const Computer& rhs);

    //c'tor
    Computer(const int& price, const std::string& manufacturer, const std::string& cpu, const bool& is_a_laptop, const int& usb);
    
    //default c'tor
    Computer();

    //d'tor
    ~Computer() {}

    //copy c'tor
    Computer(const Computer& computer);

    //print
    //prints connectede devices by order of connection
    void print_connected() const;


protected:
    int usb_oneTimeSetter() {
        static int flag = 0;
        return flag++;
    }
};

//class Observer {
//public:
//    virtual void notify(vector<PeripheralDevice*>& device) = 0;
//    virtual ~Observer() = default;
//};


#endif // !COMPUTER_H