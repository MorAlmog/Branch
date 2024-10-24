//Student Mor Almog, gm.bebel12@gmail.com 307850792

#pragma once
#include <iostream>
#include <string>

//#define PDEVICE_TYPES_NUM 3     //the amount of types of peripheral devices

/*class Item documentation:
    a pure virtual class with the following attribute

    private members:
        price:                          the price of the item
        id:                             a predetermined variable which is set during the creation of the object, cannot be changed and therefore does not have a setter
        manufacturer:                   the company which made the item

    operator overloading:
        operator std::string():         syntax: std::string(Item** item),
                                        a pure virtual function which returns a string with private members of the item listed in the following order: 
                                                id <num>: <manufacturer>, <price>$
        assignment operator=           

    other functions:
        idFunction():                   a function used only for initialising the id of each instance of the Item class


    this class is a virtual class and therfore will *not* have its own copy c'tor

*/

class Item {
    int price;
    int const id = idFunction();
    std::string manufacturer;

public:
    //getters
    int getPrice() const;
    int getId() const;
    std::string getManufacturer() const;
    
    //setters
    void setPrice(const int& price);
    void setManufacturer(const std::string& manufacturer);

    //assignment operator (op=)
    Item& operator=(const Item& rhs);
    
    //pure virtual function
    virtual operator std::string() const = 0;

    //c'tor
    Item(const int& price, const std::string& manufacturer = "~");

    //default c'tor
    Item();

    //d'tor
    virtual ~Item();

    //copy c'tor
    Item(const Item& item);

private:
    //id initialiser for each instance of a new item
    int idFunction() {
        static int _id = 0;
        return ++_id;
    }
};
