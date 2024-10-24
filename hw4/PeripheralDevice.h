//Student Mor Almog, gm.bebel12@gmail.com 307850792

#pragma once

#ifndef PERIPHERALDEVICE_HEADER
#define PERIPHERALDEVICE_HEADER

#define PDEVICE_TYPES_NUM 3     //the amount of types of peripheral devices

#define KEYBOARD_IDENTIFIER 0
#define MOUSE_IDENTIFIER 1
#define WEBCAM_IDENTIFIER 2

class Computer;

#include "Computer.h"
#include "Item.h"
#include "HWExceptions.h"


/*class PeripheralDevice documentation:
    a pure virtual derivitive class of the virtual class - Item.

    private members:
        id:                         inherited
        price:                      inherited
        manufacturer:               inherited
        colour:                     string which hold the colour of the device
        is_wireless:                bool type; true = wireless, false - wired
        identifier:					int which corresponds to the cell in which Webcam will be added to in case of connection to Computer.
                                    this is a const variable that can only be changed in the definition of WEB_ID.
        is_connected:               bool type used as a flag; true = already connected to a compute, false = not connected yet

    operator overloading:
        std::string():              syntax: std::string(PeripheralDevice** device),
                                    returns a string with all private members of the object in the following order:  id <num>: <manufacturer>, <price>$, <is_wireless>, <colour>
                                    uses the virtual operator overloading of Item, then adds its own private members to the string.
        assignment operator:        syntax: lhs_device = rhs_device;
    
    other methods:
        connect:                    recieves a pointer to computer as an arg, then prints the connection string: <device string> is connection to <computer string>


    this class is a pure virtual class and therfore will *not* have its own copy c'tor
*/

class PeripheralDevice : public Item {
	//price					//members inherited privately from Item
	//manufacturer
	//id
	std::string colour;
	bool is_wireless;
    const int identifier = identifierFunc();
    Computer* is_connected = NULL;

public:
    //setters
	void setIsWireless(const bool& is_wireless);
	void setColor(const std::string& colour);
    //void setIdentifier(const int& irrelevant);
    //void setIsConnected(Computer*& const irrelevant);
    //no setter for identifier nor for is_connected - user should not be allowed to change the var is_connected, identifier is of type const

    //getters
    bool getIsWireless() const { return is_wireless; }
    std::string getColor() const { return colour; }
    int getIdentifier() const { return identifier; }



    //operator overloading

    //cast to string - a pure method
	virtual operator std::string() const = 0;

    //assignmnet operator
    PeripheralDevice& operator=(const PeripheralDevice& rhs);

    //connect function
	virtual void connect(Computer* computer);
    //disconnet function
    virtual void disconnect();
	
    //c'tor
    PeripheralDevice(const int& price, const std::string& manufacturer, const std::string& colour, const bool& is_wireless);

    //default c'tor
    PeripheralDevice();
	
    //d'tor
    ~PeripheralDevice();

    //copy c'tor
    PeripheralDevice(const PeripheralDevice& device);

protected:
    virtual int identifierFunc() = 0;
};

#endif // !PERIPHERAL_HEADER


