//Student Mor Almog, gm.bebel12@gmail.com 307850792

#include "Item.h"
#include <string>

//getters
int Item::getPrice() const {
    return this->price;
}
std::string Item::getManufacturer() const {
    return this->manufacturer;
}
int Item::getId() const {
    return this->id;
}

//setters
void Item::setPrice(const int& _price) {
    this->price = _price;
}
void Item::setManufacturer(const std::string& _manufacturer) {
    this->manufacturer = _manufacturer;
}

//operator string() for the virtual class PeripheralDevice
//returns a string with the values of all members of the class, and passes them to its derived, non-virtual and virtual, classes
//saves each member of the item as a string
Item::operator std::string() const{
        std::string idString = "id " + std::to_string((*this).getId()) + ": ";   //used *item, both *this and *item are same type
        std::string manufacturerString = (*this).getManufacturer() + ", ";
        std::string priceString = std::to_string((*this).getPrice()) + "$";
        return (idString + manufacturerString + priceString);
}

//assignment operator (op=)
Item& Item::operator=(const Item& rhs) {
    this->price = rhs.price;
    this->manufacturer = rhs.manufacturer;
    return *this;
}

//c'tor
Item::Item(const int& price, const std::string& manufacturer) : price(price), manufacturer(manufacturer) {}

//default c'tor - notice id is already defined during creation of class using idFunction and cannot be changed
Item::Item() : price(price = 0), manufacturer(manufacturer = "~") {}

//d'tor
Item::~Item() {
    std::cout << "Throwing away an item" << std::endl;
}

//copy c'tor
Item::Item(const Item& item) : price(item.price), manufacturer(item.manufacturer) { }