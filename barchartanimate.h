// Amaan Shah, UIC, Spring 2021
// barchartanimate.h
// This class contains a dynamic array of barcharts as
// well as the functions used to create, delete, print,
// and access info about them.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used in autograder, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate:
//
class BarChartAnimate {
 private:
    // Private member variables for the abstraction:
    BarChart* barcharts;  // pointer to a C-style array (DYNAMIC)
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int colorIndex; // new varaible to keep track of index for colorMap assignment
    
    // parseLine:
    // Helper function to parse the test files in addFrame.
    string parseLine(string &line) {
        int comma = line.find(',');
        string item = line.substr(0, comma);
        line.erase(0, comma + 1);
        return item;
    }
    
    // assignColor:
    // Assigns a category to a color if not already in the colorMap
    void assignColor (string category, map<string, string> &colorMap,
    vector<string> colors, int &index) {
        if (colorMap.count(category) == 0) { // not in the map
            int size = colors.size() - 1;
            if (index == size) {
                colorMap.emplace(category, colors[index]);
                index = 0;
            } else {
                colorMap.emplace(category, colors[index]);
                index++;
            }
        }
    }
    
 public:

    // Parameterized Constructor:
    // The barcharts C-array is constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        this->capacity = 4;
        this->barcharts = new BarChart[this->capacity];
        this->size = 0;
        this->colorIndex = 0;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }
    
    // destructor:
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    virtual ~BarChartAnimate() {
        for (int i = 0; i < size; i++) {
            barcharts[i].clear();
        }
        delete[] barcharts;
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, doubles the capacity.
    void addFrame(ifstream &file) {
        if (this->size == this->capacity) {
            BarChart* temp = new BarChart[this->size * 2];
            for (int x = 0; x < size; x++) {
                temp[x] = this->barcharts[x];
            }
            delete[] barcharts;
            this->barcharts = temp;
            this->capacity = size * 2;
        }
        string empty;
        string rec;
        getline(file, empty);
        getline(file, rec);
        if(!file.fail() && rec != "") {
            int numRecords = stoi(rec);
            BarChart newChart(numRecords);
            for (int i = 0; i < numRecords; i++) {
                string barstat;
                getline (file, barstat);
                string frame = parseLine(barstat);
                string name = parseLine(barstat);
                string country = parseLine(barstat);
                string val = parseLine(barstat);
                int value = stoi(val);
                string category = barstat;
                assignColor(category, colorMap, COLORS, colorIndex);
                newChart.addBar(name, value, category);
                newChart.setFrame(frame);
            }
            this->barcharts[size] = newChart;
            this->size++;
        }
    }

    // animate:
    // this function plays each frame stored in barcharts.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
		if (endIter == -1) {
		    for (int i = 0; i < size; i++) {
		        usleep(3 * microsecond);
		        output << CLEARCONSOLE;
		        output << BLACK << title << endl;
		        output << BLACK << source << endl;
		        barcharts[i].graph(output, colorMap, top);
		        output << BLACK << xlabel << endl;
		        output << BLACK << "Frame: ";
		        output << barcharts[i].getFrame() << endl;
		    }
		} 
		else if (endIter > 0) {
		    for (int i = 0; i < endIter; i++) {
		        usleep(3 * microsecond);
		        output << CLEARCONSOLE;
		        output << BLACK << title << endl;
		        output << BLACK << source << endl;
		        barcharts[i].graph(output, colorMap, top);
		        output << BLACK << xlabel << endl;
		        output << BLACK << "Frame: ";
		        output << barcharts[i].getFrame() << endl;
		    }
		}
	}

    // getSize():
    // Returns the size of the BarChartAnimate object.
    int getSize(){
        return size;
    }

    // operator[]:
    // Returns BarChart element in BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    BarChart& operator[](int i){
       if (i < 0 || i >= capacity) {
            throw out_of_range("BarChartAnimate: i out of bounds");
        }
        return barcharts[i];
    }
};
