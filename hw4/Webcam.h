//Student Mor Almog, gm.bebel12@gmail.com 307850792

#pragma once

#include "PeripheralDevice.h"
#include <iostream>
#include <string>

#ifndef WEBCAM_H
#define WEBCAM_H


/*class Webcam documentation:
	a derivitive class of the pure virtual class - PeripheralDevice, as wel as a sub-sub class of the pure virtual class - Item

	private members:
		id:                         inherited from Item
		price:                      inherited
		manufacturer:               inherited
		colour:                     inherited from PerpheralDevice
		is_wireless:                inherited
		identifier:					inherited
		is_connected:				inherited
		resolution:					string type.
*/

class Webcam : public PeripheralDevice {
	//int price								//members inherited privately from Item, can be accessed using corresponding getters and setters
	//string manufacturer
	//int id
	//string colour;						//private memebers inherited from P.D, can be accessed using corresponding getters and setters
	//bool is_wireless;
	//const int identifier;
	//bool is_connected;
	//int identifier = WEBCAM_IDENTIFIER;
	std::string resolution;
public:
	//setters
	void setResolution(const std::string& resolution);

	//getters
	std::string getResolution() const { return resolution; }

	//operators

	//assignment operator=
	Webcam& operator=(const Webcam& rhs);

	//cast to string operator std::string()
	operator std::string() const;

	//connect override
	void connect(Computer*& computer);

	//default c'tor
	Webcam();

	//c'tor
	Webcam(const int& price, const std::string& manufacturer, const std::string& colour, const bool& is_wireless, const std::string resolution);

	//copy c'tor


	//d'tor
	~Webcam() {}

private:
	int identifierFunc() {
		return WEBCAM_IDENTIFIER;
	}
};

#endif // ! WEBCAM_H