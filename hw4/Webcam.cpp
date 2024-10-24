#include "Webcam.h"

//setters
void Webcam::setResolution(const std::string& _resolution) {
	this->resolution = _resolution;
	return;
}

//assignment operator
//uses PeripheralDevice's - Webcam's base class - operator= then draws the rest of the data from rhs's getters
Webcam& Webcam::operator=(const Webcam& rhs) {
	PeripheralDevice* lhs = this;		//casting
	*lhs = rhs;
	this->resolution = rhs.getResolution();
	return *this;
}

//operator string() for sub-sub-class Webcam
//returns a string with the values of all members of the class
Webcam::operator std::string() const {
	std::string deviceString = PeripheralDevice::operator std::string() + ", ";
	std::string resolutionString = "Webcam with resolution: " + resolution;
	return deviceString + resolutionString;
}

//connect function - override for PDevice::connect
void Webcam::connect(Computer*& computer) {
	std::cout << "Connecting a Webcam " << std::endl;
	PeripheralDevice::connect(computer);
}

//c'tor
Webcam::Webcam(const int& price, const std::string& manufacturer = "~", const std::string& colour = "~", const bool& is_wireless = false,
	const std::string resolution = "~") : PeripheralDevice(price, manufacturer, colour, is_wireless), resolution(resolution) {}

//default c'tor
Webcam::Webcam() {
	this->resolution = "~";
}