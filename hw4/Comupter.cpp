//Student Mor Almog, gm.bebel12@gmail.com 307850792

#include "Computer.h"
#include <string>

//setters
void Computer::setCpu(const std::string& _cpu) {
    this->cpu = _cpu;
    //it’s bullshit, i did not hit her. i did NOOOOTTTTT
}
void Computer::setIsALaptop(const bool& _is_a_laptop) {
    this->is_a_laptop = _is_a_laptop;
    //oh, hi mark
}


//operator string() for sub-class Computer
//returns a string with the values of all members of the class
Computer::operator std::string() const {
    std::string itemString = Item::operator std::string() + ", ";
    std::string laptopString;
    if (is_a_laptop) {
        laptopString = "Laptop, ";
    }
    else {
        laptopString = "Desktop, ";
    }

    std::string cpuString = cpu;
    return itemString + laptopString + cpuString;
}

//assignment operator=
//uses Item's - Computer's base class - operator= then draws the rest of the data from rhs's getters
Computer& Computer::operator=(const Computer& rhs) {
    Item* lhsPtr = this;            //casting - ptr of type Item* to point on type Computer
    *lhsPtr = rhs;                  //Item::operator=
    this->cpu = rhs.getCpu();       //the rest of the data
    this->is_a_laptop = rhs.getIsALaptop();

    return *this;
}

//c'tor
Computer::Computer(const int& price, const std::string& manufacturer, const std::string& cpu = "~", const bool& is_a_laptop = false, 
    const int& usb = 0) : Item(price, manufacturer), cpu(cpu), is_a_laptop(is_a_laptop), usb(usb) {}

//default c'tor
Computer::Computer() {
    this->cpu = "~";
    this->is_a_laptop = false;
    //check_if_connected.resize(PDEVICE_TYPES_NUM);   //reserve+initialise
}

//copy c'tor
Computer::Computer(const Computer& computer) : Item(computer.getPrice(), computer.getManufacturer()), cpu(computer.cpu), 
    is_a_laptop(computer.is_a_laptop) {}

//print
//
void Computer::print_connected() const {
    std::cout << "There are " << connected_devices.size() << "connections to " << std::string(*this) << std::endl;
    for (auto& i : connected_devices) {
        std::cout << std::string(*i) << std::endl;
    }
    return;
}

//protected methods

//setPort
//a utility function preventing user from setting usb twice
void Computer::setPort(const int& _usb) {
    if (usb_oneTimeSetter()) {
        throw PortError();
    }
    else {
        this->usb = _usb;
    }
}