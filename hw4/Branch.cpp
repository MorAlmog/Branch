//Student Mor Almog, gm.bebel12@gmail.com 307850792

#include "Branch.h"

using std::cout;
using std::endl;
using std::vector;


//setters
void Branch::setLocation(const std::string& _location) {
	this->location = _location;
	return;
}

//void Branch::setItemNum(const int& num){
//	this->itemNum = num;
//}
//
//void Branch::setAddingCounter(const int& num){
//	this->adding_counter = num;
//}

//void Branch::setCapacity(const int& _capacity) {
//	throw ModifyingError();
//}


//getters
std::string Branch::getLocation() const {
	return this->location;
}

vector<Item*>& Branch::getCatalog(void) {
	//num = itemNum;
	return catalog;
}

//int Branch::getItemNum() const {
//	return itemNum;
//}

//int Branch::getAddingCounter() const {
//	return adding_counter;
//}

//addItem function
//adds an item to catalog if catalog isn't full and item isn't already in catalog
void Branch::addItem(Item* item) {
	if (catalog.size() < capacity) {
		int index = add_id_binSearch(item);				//adding to catalog
		catalog.insert(catalog.begin() + index, item);

		index = add_price_binSearch(item);			//adding to price catalog, using this utility vector while keeping it sorted results a stable
		if (index == -1) {								//insertion and sorting. returning low+1 and -1 in case of high == item's price 
			catalog_by_price.push_back(item);
		}
		else {
			catalog_by_price.insert(catalog_by_price.begin() + index, item);
		}
		return;
	}
	else {
		throw FullCatalogError();
	}
}

//binary search by id
//an algorithm for a sorted vector (by id) which based on bin search alg
//if id is found - exception is thrown (trying to add the same item twice), if not - returns an index to the correct position of the new item in catalog
int Branch::add_id_binSearch(Item* item) {
	int low = 0, high = catalog.size() - 1;			
	while (high - low > 1) {						//bin search algorithm
		int mid = (high + low) / 2;
		if (catalog.at(mid)->getId() < item->getId()) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if (catalog.at(low)->getId() == item->getId() || catalog.at(high)->getId() == item->getId()) {	//item with id similar to item's id has been found
		throw ExistingItemError();
	}
	return low + 1;		//return correct placement of the newest element
}

//binary search by price
//an algorithm for a sorted vector (by id) which based on bin search alg
//if id is found - exception is thrown (trying to add the same item twice), if not - returns an index to the correct position of the new item in catalog
int Branch::add_price_binSearch(Item* item) {
	if (catalog_by_price.back()->getPrice() == item->getPrice()) {
		return -1;									//an indication. if last item in catalog_by_price has a price<=item's price, use push_back.
	}
	int low = 0, high = catalog_by_price.size() - 1;
	while (high - low > 1) {						//bin search algorithm
		int mid = (high + low) / 2;
		if (catalog.at(mid)->getPrice() <= item->getPrice()) {	//using <= instead of < keeps catalog_by_price stable sorted
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if (catalog_by_price.at(high)->getPrice() < item->getPrice()) {
		return high + 1;							//according to algorithm high+1's price>=item's price, insert item between the two
	}
	return low + 1;									//according to algorithm, low's price is guaranteed to satisfy <=item's price
}

//delete Item
//finds item in catalog using binSearch, uses 
Item* Branch::deleteItem(const int& id) {
	int index = delete_id_binSearch(id);							//find item(id)'s index
	Item* itemPtr = catalog[index];									//save pointer to item(id)
	vector<Item*>::iterator position = catalog.begin() + index;		//position of item called for deletion
	catalog.erase(position);										//remove from catalog

	position = std::find(catalog_by_price.begin(), catalog_by_price.end(), itemPtr);		//find item in catalog_by_price in linear time
	catalog_by_price.erase(position);														//remove from catalog_by_price
	return itemPtr;
}

//delete item - bin search by id
//uses bin search algorithm (vector is sorted), if id found - returns its position in vector, 
//else - an exception is thrown (trying to delete a non-existing item from catalog)
int Branch::delete_id_binSearch(const int& id) {
	int low = 0, high = catalog.size() - 1;
	while (high - low > 1) {						//bin search algorithm
		int mid = (high + low) / 2;
		if (catalog.at(mid)->getId() < id) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	if (catalog[high]->getId() == id) {			//returns position - option one
		return high;
	}
	else if (catalog[low]->getId() == id) {		//returns position - option two
		return low;
	}
	else {
		throw NoneExistingItemError();			//id wasn't found
	}
}

//print catalog by price
//uses operator overload of std::string to print items, vector is already sorted
void Branch::print_catalog_by_price() {
	for (auto i : catalog_by_price) {
		cout << std::string(*i) << endl;
	}
}

//print catalog by id
//uses operator overload of std::string to print items, vector is already sorted in a stable sort method
void Branch::print_catalog_by_id() {
	for (auto i : catalog) {
		cout << std::string(*i) << endl;
	}
}

//c'tor
Branch::Branch(const std::string& _location, const int& _capacity) : location(_location), capacity(_capacity) {
	catalog.resize(0);
	catalog_by_price.resize(0);
}

//default c'tor
//initialises all private members
Branch::Branch() {
	location = "~";
	capacity = 0;
	catalog.resize(0);				//resize initialises vector, ensuring not exceeding will be done in addItem 
	catalog_by_price.resize(0);
}

//Branch::Branch() {
//	this->location = "~";
//	this->catalog = new Item * [BRANCH_SIZE];
//	for (int i = 0; i < BRANCH_SIZE; i++) {
//		this->catalog[i] = NULL;
//	}
//	this->itemNum = 0;
//	this->adding_counter = 0;
//}

//copy c'tor
Branch::Branch(const Branch& branch)
{
	location = branch.location;
	capacity = branch.capacity;
}

//d'tor
Branch::~Branch() {

}

/*
just one more till we're done
untill then hope i won't drown
as promised, here's your crown
after all - 
https://youtu.be/XAg5KjnAhuU?t=84
*/

