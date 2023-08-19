// Amaan Shah, UIC, Spring 2021
// bar.h
// This class holds the varaiables for a single bar and
// the different functions to get these variables or compare
// a bar to another bar.

#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;

//
// Bar:
//
class Bar {
 private:
    // Private member variables for a Bar object:
    string name;
    int value;
    string category;

 public:

    // Default constructor:
    Bar() {
        name = "";
        value = 0;
        category = "";
    }
    
    
    // Parameterized constructor:
    Bar(string name, int value, string category) {
        this->name = name;
        this->value = value;
        this->category = category;
    }

    // destructor:
    virtual ~Bar() {
        // not needed for this class
    }

    // Returns the name of a bar:
	string getName() {
        return name;
	}

    // Returns the value of a bar:
	int getValue() {
        return value;
	}

    // Returns the category of a bar:
	string getCategory() {
        return category;
	}

    // Less Than Operator, returns true is this < other:
	bool operator<(const Bar &other) const {
        return (this->value < other.value);
	}
    
    // Less Than or Equal Operator, returns true if this <= other:
	bool operator<=(const Bar &other) const {
        return ((this->value < other.value) || (this->value == other.value));
	}
    
    // Greater Than Operator, returns true is this > other:
	bool operator>(const Bar &other) const {
        return (this->value > other.value);
	}
    
    // Greater Than or Equal Operator, returns true if this >= other:
	bool operator>=(const Bar &other) const {
        return ((this->value > other.value) || (this->value == other.value));
	}
};

