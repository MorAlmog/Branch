//Student Mor Almog, gm.bebel12@gmail.com 307850792

#include "Mouse.h"

//getter
void Mouse::setDpi(const int& _dpi) {
	this->dpi = _dpi;
	return;
}

////setter
//int Mouse::getDpi() const {
//	return this->dpi;
//}


//assignment operator
//uses PeripheralDevice's - Mouse's base class - operator= then draws the rest of the data from rhs's getters
Mouse& Mouse::operator=(const Mouse& rhs) {
	PeripheralDevice* lhs = this;		//casting
	*lhs = rhs;							//P.Device::operator=
	this->dpi = rhs.getDpi();			//copies new data
	return *this;
}

//operator string() for sub-sub-class Mouse
//returns a string with the values of all members of the class
Mouse::operator std::string() const {
	std::string pdString = PeripheralDevice::operator std::string() + ", ";
	std::string dpiString = "Mouse with dpi : " + std::to_string((*this).getDpi());
	std::string mouseString = pdString + dpiString;
	return mouseString;
}

//connect function - override for PDevice::connect
void Mouse::connect(Computer*& computer) {
	std::cout << "Connecting a Mouse" << std::endl;
	PeripheralDevice::connect(computer);
}

//c'tor
Mouse::Mouse(const int& price, const std::string& manufacturer = "~", const std::string& colour = "~", const bool& is_wireless = false,
	const int& dpi = 0) : PeripheralDevice(price, manufacturer, colour, is_wireless), dpi(dpi) {}

//default c'tor
Mouse::Mouse() {
	this->dpi = 0;
}

//copy c'tor
//will cast this to be p.Device, then use P.Device::operator=
Mouse::Mouse(const Mouse& mouse) {
	PeripheralDevice* mousePtr = this;			//casting, pdPtr is of type PeripheralDevice* but points to this
	*mousePtr = mouse;							//P.Device::operator=
	this->dpi = mouse.getDpi();					//copies new data
}