//Student Mor Almog, gm.bebel12@gmail.com 307850792
#pragma once

#include "PeripheralDevice.h"

#ifndef MOUSE_HEADER
#define MOUSE_HEADER

#include <typeinfo>
#include <string>

/*class Mouse documentation:
	a derivitive class of the pure virtual class - PeripheralDevice, as wel as a sub-sub class of the pure virtual class - Item

	private members:
		id:                         inherited from Item
		price:                      inherited
		manufacturer:               inherited
		colour:                     inherited from PerpheralDevice
		is_wireless:                inherited
		dpi:						int type, holds the dpi value of the mouse

	operator overloading:
		std::string():              syntax: std::stringMouse** device),
									returns a string with all private members of the object in the following order:  
									id <num>: <manufacturer>, <price>$, <is_wireless>, <colour>, Mouse with dpi: <dpi>
									uses the virtual operator overloading of PeripheralDevice, then adds its own private members to the string.
		assignment operator:        syntax: lhs_device = rhs_device;
		
	other methods:
		connect:					an override of the PeripheralDevice virtual function - connect.
*/


class Mouse : public PeripheralDevice {
	//int price								//members inherited privately from Item, can be accessed using corresponding getters and setters
	//string manufacturer
	//int id
	//string colour;						//private memebers inherited from P.D, can be accessed using corresponding getters and setters
	//bool is_wireless;
	//int identifier = MOUSE_IDENTIFIER;
	int dpi;
public:
	//dpi setter and getter:
	void setDpi(const int& dpi);
	int getDpi() const { return dpi; }

	//override of connect function
	void connect(Computer*& computer);

	//default c'tor
	Mouse();

	//c'tor
	Mouse(const int& price, const std::string& manufacturer, const std::string& colour, const bool& is_wireless, const int& dpi);
	
	//d'tor
	~Mouse() {}

	//copy c'tor
	Mouse(const Mouse& mouse);
	
	//assignment operator (op=)
	Mouse& operator=(const Mouse& rhs);

	//string cast operator
	operator std::string() const;

private:
	int identifierFunc() {
		return MOUSE_IDENTIFIER;
	}
};

#endif