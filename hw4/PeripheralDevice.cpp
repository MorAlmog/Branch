//Student Mor Almog, gm.bebel12@gmail.com 307850792

#include "PeripheralDevice.h"

//setters
void PeripheralDevice::setIsWireless(const bool& _is_wireless) {
	this->is_wireless = _is_wireless;
}
void PeripheralDevice::setColor(const std::string& _colour) {
	this->colour = _colour;
}
//both setters exist solely HW requirment of providing setters for all private members
//void PeripheralDevice::setIdentifier(const int& irrelevant) {
//	throw ModifyingError();
//}
//void PeripheralDevice::setIsConnected(Computer*& const irrelevant) {
//	throw ModifyingError();
//}


//assignment operator
//uses Item's - PeripheralDevice's base class - operator= then draws the rest of the data from rhs's getters
PeripheralDevice& PeripheralDevice::operator=(const PeripheralDevice& rhs) {
	Item* lhs = this;		//casting to item
	*lhs = rhs;
	this->colour = rhs.getColor();
	this->is_wireless = rhs.getIsWireless();
	return *this;
}

//operator std::string()
//for virtual sub-class PeripheralDevice
//returns a string with the values of all members of the class, and passes them to its derived, non-virtual, classes
PeripheralDevice::operator std::string() const{
	std::string itemString = Item::operator std::string() + ", ";		//Item::operator
	std::string colourString = colour;
	std::string wirelessString;
	if (is_wireless) {
		wirelessString = "Wireless, ";
	}
	else {
		wirelessString = "Wired, ";
	}
	return itemString + wirelessString + colourString;
}

//connect function
//performs a dynammic_cast check in order to determind which p.device called the function, then draws its corresponding string using Class::operator std::string
void PeripheralDevice::connect(Computer* computer) {		//*this is device
	std::cout << this->operator std::string() << " is Connecting to computer: " << computer->operator std::string() << std::endl;

	vector<PeripheralDevice*>& _connected = computer->getConnectedDevices();	//ref to vec, acts exactly like vec
	bool* _check = computer->getCheckIfConnected();
	
	if (_check[this->identifier] == false) {		//empty in its indicator cell 
		if (this->is_connected == NULL) {			//device is not connected to a computer
			if (_connected.size() < computer->getPort()) {		//no more connections than its usb port number
				//can be connected!
				_connected.push_back(this);											//connect device to computer
				_check[this->identifier] = true;									//raise computer's flag for connection of the device type
				this->is_connected = computer;										//""connect"" computer to device
			}
			else {
				throw ConnectError();				//no available usb port for device
			}
		}
		else {										//computer does not have a connection the device's type, while device's connection is not NULL
			throw ConnectError();					//device is already connected to a different computer
		}
	}
	else if(this->is_connected != computer) {		//check if device is the one connected to computer
		throw ConnectError();						
	}
	//device is now (or already) connected to computer.
	return;											
}

//disconnect function
//deletes pdevice from computer's connected devices, returns the flag in the device's identifier cell in the check array to false
//and deletes the computer from pdevice's connection slot. 
void PeripheralDevice::disconnect() {
	if (is_connected) {		//connected to a computer
		Computer* computerPtr = is_connected;
		bool* _checkPtr = computerPtr->getCheckIfConnected();
		vector<PeripheralDevice*>& _connectedPtr = computerPtr->getConnectedDevices();

		vector<PeripheralDevice*>::iterator it = std::find(_connectedPtr.begin(), _connectedPtr.end(), this);		//find and erae device from computer's connected_devices
		if (it != _connectedPtr.end()) {
			_connectedPtr.erase(it);
		}
	}
}

//copy c'tor
PeripheralDevice::PeripheralDevice(const PeripheralDevice& device) {
	*this = device;
}

//c'tor
PeripheralDevice::PeripheralDevice(const int& price, const std::string& manufacturer = "~", const std::string& colour = "~", 
	const bool& is_wireless = false) : Item(price, manufacturer), colour(colour), is_wireless(is_wireless) { }

//default c'tor
PeripheralDevice::PeripheralDevice() {
	this->colour = "~";
	this->is_wireless = false;
	this->is_connected = NULL;
}

//d'tor
//disconnect on deletion - case of not connected to computer is handled inside disconnect function
PeripheralDevice::~PeripheralDevice() {
	disconnect();
}