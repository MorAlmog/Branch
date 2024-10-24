//Student Mor Almog, gm.bebel12@gmail.com 307850792
#pragma once
#define DEFAULT_CAPACITY 0

#ifndef BRANCH_H
#define BRANCH_H

class Computer;

#include "Computer.h"
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <string>
#include "Item.h"
#include "HWExceptions.h"

using std::vector;


/*class Branch documentation
	
	privater members:
		location:				represented by a string
		catalog:				an array of pointer to Item objects (and its derivatives), array's size - BRANCH_SIZE (defaulted to 10)
		itemNum;				a counter which holds the number of items in catalog
		adding_counter:			a counter which holds the number of time an item was added to catatlog, is used to determined the position of a newly added item instead of a thrown one
		capacity:				a one time modifiable variable - 
	methods:
		addItem:				receives a pointer to Item and adds it to the next open space in catalog. if there is no empty cell to hold the pointer,
								the method will replace the old item with a new one by replacing the pointers - we do not want to delete the thrown item's data! we just don't want it
								as part of our catalog.
*/

class Branch {
	std::string location;
	vector<Item*> catalog;
	//int itemNum;
	//int adding_counter;
	int capacity;
	vector<Item*> catalog_by_price;

public:
	//getters
	vector<Item*>& getCatalog(void);
	std::string getLocation() const;
	//int getItemNum() const;
	//int getAddingCounter() const;
	
	//setter
	void setLocation(const std::string& location);
	//void setItemNum(const int& num);
	//void setAddingCounter(const int& num);
	//void setCapacity(const int& capacity);

	//add item to catalog
	void addItem(Item* item);

	//delete Item
	//removes item from catalog, and from utility vector (catalog_by_price).
	Item* deleteItem(const int& id);

	//retrieve finest Item
	//returns a ptr of the priciest item of the same type of the scpecified derived class
	template<typename T>
	T retrieveFinest(T& const item) {
		int max = 0;
		T finestPtr = NULL;
		for (int i = 0; i < catalog_by_price.size(); i++) {
			if (typeid(catalog_by_price.at(i)) == typeid(item)) {
				max = catalog_by_price.at(i)->getPrice();		//sorted array guarentees item i to have a higher price
				finestPtr = dynamic_cast<T>(catalog_by_price[i]);				//saving ptr to current priciest item
			}
		}
		if (!finestPtr) {						//none were found
			throw NoneExistingItemTypeError();
		}
		return finestPtr;
	}

	//print catalog by id
	void print_catalog_by_id();

	//print catalog by price
	void print_catalog_by_price();


	//c'tor
	Branch(const std::string& _location, const int& _capacity);

	//default c'tor
	Branch();

	//copy c'tor
	Branch(const Branch& branch);
	
	//d'tor
	~Branch();

	//utility sorting functions
	int add_id_binSearch(Item* item);
	int add_price_binSearch(Item* item);
	int delete_id_binSearch(const int& id);
	int maxFunc(const int& a, const int& b) {
		return ((a < b) ? b : a);
	}
	
	//template<typename V, typename F>
	//int delete_binSearch(const int& key, V vector, F getKey()) {
	//	int low = 0, high = catalog.size() - 1;
	//	while (high - low > 1) {						//bin search algorithm
	//		int mid = (high + low) / 2;
	//		if (catalog.at(mid)->getId() < id) {
	//			low = mid + 1;
	//		}
	//		else {
	//			high = mid;
	//		}
	//	}
	//}
};

#endif // !BRANCH_H