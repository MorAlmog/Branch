#pragma once

#ifndef HW4_HWEXCEPTIONS_H
#define HW4_HWEXCEPTIONS_H

#include <iostream>
#include <exception>

//exception classes

//
class ExistingItemError : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Trying to add an item with an id already in the catalog";
    }
};

//
class FullCatalogError : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Trying to add an item to a full catalog";
    }
};

//
class NoneExistingItemError : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Trying to delete an item with a non existing type";
    }
};

//
class NoneExistingItemTypeError : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Trying to get an item with a non existing type";
    }
};

//an exception class for an existing item the vector
class ConnectError : public std::exception {
public:
    virtual const char* what() const throw()
    {
        return "Failed connection attempt";
    }
};

//Port Error
//an exception for trying to set usb port a second time
class PortError : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Cannot modify usb port after initial setting";
    }
};

//Modifying Error
//an exception for trying to modity a private member which should not be modified - ruins the code's logic!
//only exists for HW requirements of having setters for all private members 
class ModifyingError : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Modifying this private member is not allowed";
    }
};

#endif
