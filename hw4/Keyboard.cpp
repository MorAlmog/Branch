//Student Mor Almog, gm.bebel12@gmail.com 307850792

#include "Keyboard.h"

////getter
//int Keyboard::getNumOfKeys() const {
//	return this->keys;
//}

//setter
void Keyboard::setNumOfKeys(const int& _keys) {
	this->keys = _keys;
	return;
} 

//assignment operator
//uses PeripheralDevice's - Keyboard's base class - operator= then draws the rest of the data from rhs's getters
Keyboard& Keyboard::operator=(const Keyboard& rhs) {
	PeripheralDevice* lhs = this;		//casting
	*lhs = rhs;
	this->keys = rhs.getNumOfKeys();
	return *this;
}

//operator string() for sub-sub-class Keyboard
//returns a string with the values of all members of the class
Keyboard:: operator std::string() const {
	std::string deviceString = PeripheralDevice::operator std::string() + ", ";
	std::string keysString = "Keyboard with " + std::to_string(keys) + " keys";
	return deviceString + keysString;
}

//connect function - override for PDevice::connect
void Keyboard::connect(Computer*& computer) {
	std::cout << "Connecting a Keyboard " << std::endl;
	PeripheralDevice::connect(computer);
}

//c'tor
Keyboard::Keyboard(const int& price, const std::string& manufacturer = "~", const std::string& colour = "~", const bool& is_wireless = false, 
	const int& keys = 0) : PeripheralDevice(price, manufacturer, colour, is_wireless), keys(keys) {}

//Computer* const is_connected = NULL

//default c'tor
Keyboard::Keyboard() {
	this->keys = 0;
}

//copy c'tor
Keyboard::Keyboard(const Keyboard& keyboard) {
	PeripheralDevice* device = this;		//casting
	*device = keyboard;						//P.Device::operator=
	this->keys = keyboard.getNumOfKeys();	//copies new data
}