//Student Mor Almog, gm.bebel12@gmail.com 307850792

#pragma once

#include "PeripheralDevice.h"
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <iostream>
#include <string>

/*class Keyboard documentation:
	a derivitive class of the pure virtual class - PeripheralDevice, as wel as a sub-sub class of the pure virtual class - Item

	private members:
		id:                         inherited from Item
		price:                      inherited
		manufacturer:               inherited
		colour:                     inherited from PerpheralDevice
		is_wireless:                inherited
		key:						int type, holds the number of keys in keyboard

	operator overloading:
		std::string():              syntax: std::stringMouse** device),
									returns a string with all private members of the object in the following order:
									id <num>: <manufacturer>, <price>$, <is_wireless>, <colour>, Keyboard with <keys> keys
									uses the virtual operator overloading of PeripheralDevice, then adds its own private members to the string.
		assignment operator:        syntax: lhs_device = rhs_device;

	other methods:
		connect:					an override of the PeripheralDevice virtual function - connect. 
*/

class Keyboard : public PeripheralDevice {
	//price					//priavte memebers inherited from Item
	//manufacturer
	//id
	//string colour;		//private memeberes inherited from PeripheralDevice
	//bool is_wireless;
	//int identifier = KEYBOARD_IDENTIFIER;
	int keys;
public:

	//setter
	void setNumOfKeys(const int& keys);

	//getter
	int getNumOfKeys() const { return keys; }

	//operator overloading

	//operator=
	Keyboard& operator=(const Keyboard& rhs);

	//operator std::string()
	operator std::string() const;

	//override of connect function
	void connect(Computer*& computer);

	//c'tor
	Keyboard(const int& price, const std::string& manufacturer, const std::string& colour, const bool& is_wireless, const int& keys);

	//default c'tor
	Keyboard();

	//copy c'tor
	Keyboard(const Keyboard& keyboard);

	//d'tor
	~Keyboard() {}
	
private:
	int identifierFunc() {
		return KEYBOARD_IDENTIFIER;
	}
};



#endif // !KEYBOARD_H