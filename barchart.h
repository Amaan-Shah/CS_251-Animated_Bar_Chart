// Amaan Shah, UIC, Spring 2021
// barchart.h
// This class contains an array of bars as well as
// the functios used to create, delete, print, or get
// other information about the bars in the chart

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"

using namespace std;

// Constants used for bar chart animation
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

//
// BarChart:
//
class BarChart {
 private:
    // Private member variables for the abstraction:
    Bar* bars;  // pointer to a C-style array (NOT DYNAMIC)
    int capacity;
    int size;
    string frame;
    
    // Helper function to print out each bar in a barchart:
    void printBar (int i, int size, map<string, string> &colorMap, ostream &output) {
        string category = bars[i].getCategory();
        string color;
        if (colorMap.count(category) == 1) { //category is in the map
            color = colorMap[category];
        } else {
            color = BLACK;
        }
        string bar = "";
        for (int i = 0; i < size; i++) {
            bar += BOX;
        }
        output << color << bar << " " << bars[i].getName();
        output << " " << bars[i].getValue() << endl;
    }
    
 public:
    
    // default constructor:
    BarChart() {
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }
    
    // parameterized constructor
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
        if (n > 0) {
            this->bars = new Bar[n];
            this->capacity = n;
            this->size = 0;
            this->frame = "";
        } 
    }

    // copy constructor:
    // Creates a new barchart that is exactly the same as the one
    // passed into the function.
    BarChart(const BarChart& other) {
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;
        for (int i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }
    }
    
    // copy operator=
    // Makes a barchart an exact copy of another barchart.
    BarChart& operator=(const BarChart& other) {
        if (this == &other) {
            return *this;
        }
        delete [] this->bars;
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        this->frame = other.frame;
        for (int i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }
        return *this;
    }

    // clear:
    // frees memory and resets all private member variables to default values.
    void clear() {
        delete [] this->bars;
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }
    
    // destructor:
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    virtual ~BarChart() {
        if (bars != nullptr) {
            delete [] this->bars;
        }
    }
    
    // setFrame
    void setFrame(string frame) {
    	this->frame = frame;
    }
    
    // getFrame():
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        return frame;
    }

    // addBar:
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        if (size == capacity) {
            return false;
        }
        Bar x(name, value, category);
        bars[size] = x;
        size++;
        return true;
    }
    
    // getSize():
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return size;
    }
    
    // operator[]:
    // Returns Bar element in BarChart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds".
    Bar& operator[](int i) {
        if (i < 0 || i >= capacity) {
            throw out_of_range("BarChart: i out of bounds");
        }
        return bars[i];
    }
    
    // dump:
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        if (capacity > 0) {
            sort(bars, bars + capacity, greater<Bar>());
            output << "frame: " << frame << endl;
            for (int i = 0; i < size; i++) {
                output << bars[i].getName() << " ";
                output << bars[i].getValue() << " ";
                output << bars[i].getCategory() << endl;
            }
        }
    }
    
    // graph:
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;
    	int count = 0;
    	if (capacity > 0) {
            sort(bars, bars + capacity, greater<Bar>());
            for (int i = 0; i < size; i++) {
                if (i == 0 && count < top) {
                    int size = lenMax;
                    printBar(i, size, colorMap, output);
                } else if (count < top) {
                    double x = bars[i].getValue();
                    int y = bars[0].getValue();
                    double boxes = (x / y);
                    int size = boxes * lenMax;
                    printBar(i, size, colorMap, output);
                }
                count++;
            }
        }
    }
    
};

