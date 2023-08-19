// Amaan Shah, UIC, Spring 2021
// test.cpp
// File used to perform local test on the functions
// used in Project 3.

#include <iostream>
#include "barchartanimate.h"
using namespace std;

// Bar.h Tests:
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testLToperator() { // want a < b to be true
    int x = 2;
    int y = 5;
    
    Bar a("a", x, "US");
    Bar b("b", y, "Canada");
    
    if (!(a < b)) {
        cout << "testLToperator: Failed" << endl;
        return false;
    } else if (a.getValue() == b.getValue()) {
        cout << "testLToperator: Failed (a = b)"<< endl;
        return false;
    }
    cout << "testLToperator: all passed!" << endl;
    return true;
}

bool testLTEoperator() { // want a <= b to be true
    int x = 1;
    int y = 2;
    int z = 2;
    
    Bar a("a", x, "US");
    Bar b("b", y, "Canada");
    Bar c("c", z, "Mexico");
    
    if (!(a < b)) {
        cout << "testLTEoperator: Failed !(a < b)" << endl;
        return false;
    } else if (!(b <= c)) {
        cout << "testLTEoperator: Failed (!a <= b)" << endl;
        return false;
    }
    cout << "testLTEoperator: all passed!" << endl;
    return true;
}

bool testGToperator() { // want a > b to be true
    int x = 4;
    int y = 3;
    
    Bar a("a", x, "US");
    Bar b("b", y, "Canada");
    
    if (!(a > b)) {
        cout << "testGToperator: Failed !(a > b)" << endl;
        return false;
    } else if (a.getValue() == b.getValue()) {
        cout << "testGToperator: Failed (a = b)" << endl;
        return false;
    }
    cout << "testGToperator: all passed!" << endl;
    return true;
}

bool testGTEoperator() { // want a >= b to be true
    int x = 7;
    int y = 7;
    int z = 6;
    
    Bar a("a", x, "US");
    Bar b("b", y, "Canada");
    Bar c("c", z, "Mexico");
    
    if (!(a > c)) {
        cout << "testGTEoperator: Failed !(a > b)" << endl;
        return false;
    } else if (!(a >= b)) {
        cout << "testGTEoperator: Failed !(b >= c)" << endl;
    }
    cout << "testGTEoperator: all passed!" << endl;
    return true;
}

bool testgetName() {
    Bar a;
    Bar b("Chicago", 9234324, "US");
    
    if(a.getName() != "") {
        cout << "testgetName: Failed (def const)" << endl;
        return false;
    } else if (b.getName() != "Chicago") {
        cout << "testgetName: Failed (param const)" << endl;
        return false;
    }
    cout << "testgetName: all passed!" << endl;
    return true;
}

bool testgetValue() {
    Bar a;
    Bar b("Chicago", 9234324, "US");
    
    if(a.getValue() != 0) {
        cout << "testgetValue: Failed (def const)" << endl;
        return false;
    } else if (b.getValue() != 9234324) {
        cout << "testgetValue: Failed (param const)" << endl;
        return false;
    }
    cout << "testgetValue: all passed!" << endl;
    return true;
}

bool testgetCategory() {
    Bar a;
    Bar b("Chicago", 9234324, "US");
    
    if(a.getCategory() != "") {
        cout << "testgetCategory: Failed (def const)" << endl;
        return false;
    } else if (b.getCategory() != "US") {
        cout << "testgetCategory: Failed (param const)" << endl;
        return false;
    }
    cout << "testgetCategory: all passed!" << endl;
    return true;
}


// Barchart.h Tests:
bool testBarChartDefaultConstructor() {
    BarChart bc;
    if (bc.getSize() != 0) {
        cout << "testBarChartDefaultConstructor: getsize() failed" << endl;
        return false;
    } else if (bc.getFrame() != "") {
        cout << "testBarChartDefaultConstructor: gerFrame() failed" << endl;
        return false;
    }
    cout << "testBarChartDefaultConstructor: all passed!" << endl;
    return true;
    
}

bool testBarChartParamConstructor() {
    BarChart bc(10);
    if (bc.getSize() != 0) {
        cout << "testBarChartParamConstructor: getSize() failed" << endl;
        return false;
    } else if (bc.getFrame() != "") {
        cout << "testBarChartParamConstructor: getFrame() failed" << endl;
        return false;
    }
    cout << "testBarChartParamConstructor: all passed!" << endl;
    return true;
}

bool testsetFrame() {
    BarChart a;
    a.setFrame("123");
    
    BarChart b(10);
    b.setFrame("456");
    
    if (a.getFrame() != "123") {
        cout << "testsetFrame: Failed. (def const)" << endl;
        return false;
    } else if (b. getFrame() != "456") {
        cout << "testsetFrame: Failed. (param const)" << endl;
        return false;
    }
    cout << "testsetFrame: all passed!" << endl;
    return true;
}

bool testgetFrame() {
    BarChart a;
    a.setFrame("123");
    string test1 = a.getFrame();
    
    BarChart b(10);
    b.setFrame("456");
    string test2 = b.getFrame();
    
    if (test1 != "123") {
        cout << "testgetFrame: Failed. (def const)" << endl;
        return false;
    } else if (test2 != "456") {
        cout << "testgetFrame: Failed. (param const)" << endl;
        return false;
    }
    cout << "testgetFrame: all passed!" << endl;
    return true;
}

bool testaddBar() {
    BarChart x;
    BarChart y(2);
    bool test = x.addBar("first", 0, "test");
    bool test1 = x.addBar("Chicago", 123,"USA");
    bool test2 = y.addBar("a", 1, "A");
    bool test3 = y.addBar("b", 2, "B");
    bool test4 = y.addBar("c", 3, "C");
    bool test5 = y.addBar("d", 4, "D");
    
    if (test) {
        cout << "testaddBar: Failed (def const, test)" << endl;
        return false;
    } else if (test1) {
        cout << "testaddBar: Failed (def const, test1)" << endl;
        return false;
    } else if (!test2) {
        cout << "testaddBar: Failed (param const, test 2)" << endl;
        return false;
    } else if (!test3) {
        cout << "testaddBar: Failed (param const, test 3)" << endl;
        return false;
    } else if (test4) {
        cout << "testaddBar: Failed (param const, test 4)" << endl;
        return false;
    } else if (test5) {
        cout << "testaddBar: Failed (param const, test 5)" << endl;
        return false;
    }
    cout << "testaddBar: all passed!" << endl;
    return true;
}

bool testgetSize() {
    BarChart x;
    BarChart y(2);
    
    int a = x.getSize();
    if (a != 0) {
        cout << "testgetSize: Failed (def const, before add)" << endl;
        return false;
    }
    x.addBar("a", 1, "A");
    a = x.getSize();
    if (a != 0) {
        cout << "testgetSize: Failed (def const, after add)" << endl;
        return false;
    }
    int b = y.getSize();
    if (b != 0) {
        cout << "testgetSize: Failed (param const, before add)" << endl;
        return false;
    }
    y.addBar("a", 1, "A");
    b = y.getSize();
    if (b != 1) {
         cout << "testgetSize: Failed (param const, after first add)" << endl;
        return false;
    }
    y.addBar("a", 1, "A");
    b = y.getSize();
    if (b != 2) {
         cout << "testgetSize: Failed (param const, after second add)" << endl;
        return false;
    }
    y.addBar("a", 1, "A");
    b = y.getSize();
    if (b != 2) {
         cout << "testgetSize: Failed (param const, after third add)" << endl;
        return false;
    }
    cout << "testgetSize: all passed!" << endl;
    return true;
}

bool testBracketOp () {
    BarChart x(3);
    
    x.addBar("Chicago", 1020, "US");
    x.addBar("NYC", 1300, "US");
    x.addBar("Paris", 1200, "France");
    
    int i = 0;
    if (x[i].getName() != "Chicago" || x[i].getValue() != 1020 || x[i].getCategory() != "US") {
        cout << "testBracketOp: Failed (param const, 1st add)" << endl;
        return false;
    }
    i++;
    if (x[i].getName() != "NYC" || x[i].getValue() != 1300 || x[i].getCategory() != "US") {
        cout << "testBracketOp: Failed (param const, 2nd add)" << endl;
        return false;
    }
    i++;
    if (x[i].getName() != "Paris" || x[i].getValue() != 1200 || x[i].getCategory() != "France") {
        cout << "testBracketOp: Failed (param const, 3rd add)" << endl;
        return false;
    }
    
    try {
        BarChart y;
        int i = 0;
        cout << y[i].getName() << endl;
        cout << y[i].getValue() << endl;
        cout << y[i].getCategory() << endl;
        cout << endl;
        cout << "testBracketOp: Failed (def const, non-existing elements being accessed) << endl";
        return false;
        
    }
    catch (exception &x) {
        cout << "testBracketOp: all passed!" << endl;
        return true;
    }
}

bool testDump() {
    BarChart x(3);
    BarChart y(3);
    
    x.addBar("Chicago", 1020, "US");
    x.addBar("NYC", 1300, "US");
    x.addBar("Paris", 1200, "France");
    x.setFrame("123");
  
    y.addBar("NYC", 1300, "US");
    y.addBar("Paris", 1200, "France");
    y.addBar("Chicago", 1020, "US");
    y.setFrame("123");
    
    cout << endl << "COUT:" << endl;
    x.dump(cout);

    cout << endl << "SS:" << endl;
    stringstream ss("");
    x.dump(ss);
    cout << ss.str();
    cout << endl;
    
    for (int i = 0; i < 3; i++){
        if (x[i].getName() != y[i].getName()) {
            cout << "testDump: Failed (names different at index " << i << endl;
            return false;
        } else if (x[i].getValue() != y[i].getValue()) {
            cout << "testDump: Failed (values different at index " << i << endl;
            return false;
        } else if (x[i].getCategory() != y[i].getCategory()) {
            cout << "testDump: Failed (categories different at index " << i << endl;
            return false;
        }
    }

    cout << "testDump: all passed!" << endl << endl;;
    return true;
}

bool testgraph() {
    int n = 4;
    BarChart x(n);
    x.addBar("Chicago", 1020, "US");
    x.addBar("NYC", 1300, "US");
    x.addBar("Paris", 1200, "France");
    x.addBar("test", 500, "notinmap");
    x.setFrame("123");
    
    BarChart y(n);
    y.addBar("NYC", 1300, "US");
    y.addBar("Paris", 1200, "France");
    y.addBar("Chicago", 1020, "US");
    y.addBar("test", 500, "notinmap");
    y.setFrame("123");
    
    map<string, string> colorMap;
    colorMap["US"] = RED;
    colorMap["France"] = BLUE;
    x.graph(cout, colorMap, n);
    cout << endl;
    y.graph(cout, colorMap, n);
    
    for (int i = 0; i < n; i++) {
        if (x[i].getName() != y[i].getName()) {
            cout << "testGraph: Failed (names different at index " << i << endl;
            return false;
        } else if (x[i].getValue() != y[i].getValue()) {
            cout << "testGraph: Failed (values different at index " << i << endl;
            return false;
        } else if (x[i].getCategory() != y[i].getCategory()) {
            cout << "testGraph: Failed (categories different at index " << i << endl;
            return false;
        } else if (x.getFrame() != y.getFrame()) {
            cout << "testGraph: Failed (frames different)" << endl;
            return false;
        }
    }
    cout << endl << "testGraph: all passed!" << endl;
    return true;
}

bool testCopyConst() {
    BarChart x(10);
    BarChart xcopy(x);
    
    if (xcopy.getSize() != x.getSize()) {
        cout << "testCopyConst: Failed, sizes not the same" << endl;
        return false;
    } else if (xcopy.getFrame() != x.getFrame()) {
        cout << "testCopyConst: Failed, frames are not the same" << endl;
        return false;
    }
    
    for (int i = 0; i < x.getSize(); i++) {
        if (xcopy[i].getName() != x[i].getName()) {
            cout << "testCopyConst: Failed, different name at index " << i << endl;
            return false;
        } else if (xcopy[i].getValue() != x[i].getValue()) {
            cout << "testCopyConst: Failed, different vals at index " << i << endl;
            return false;
        } else if (xcopy[i].getCategory() != x[i].getCategory()) {
            cout << "testCopyConst: Failed, different cat. at index " << i << endl;
            return false;
        }
    }
    
    cout << "testCopyConst: all passed!" << endl;
    return true;
}

bool testCopyOpEq() {
    BarChart x(2);
    BarChart y(3);
    
    x.addBar("Amaan", 1000, "First");
    x.addBar("Shah", 750, "Last");
    x.setFrame("22");
    
    BarChart temp(x);
    
    y.addBar("Hello", 2500, "US");
    y.addBar("World", 2000, "US");
    y.addBar("Hi", 1000, "US");
    y.setFrame("100");
    
    x = x;
    for (int i = 0; i < x.getSize(); i++) {
        if (x[i].getName() != temp[i].getName()) {
            cout << "testCopyOpEq: Failed (x = x), name changed" << endl;
            return false;
        } else if (x[i].getValue() != temp[i].getValue()) {
            cout << "testCopyOpEq: Failed (x = x), val changed" << endl;
            return false;
        } else if (x[i].getCategory() != temp[i].getCategory()) {
            cout << "testCopyOpEq: Failed (x = x), cat changed" << endl;
            return false;
        }
    }
    
    x = y;
    for (int i = 0; i < x.getSize(); i++) {
        if (x[i].getName() != y[i].getName()) {
            cout << "testCopyOpEq: Failed (x = y), name changed" << endl;
            return false;
        } else if (x[i].getValue() != y[i].getValue()) {
            cout << "testCopyOpEq: Failed (x = y), val changed" << endl;
            return false;
        } else if (x[i].getCategory() != y[i].getCategory()) {
            cout << "testCopyOpEq: Failed (x = y), cat changed" << endl;
            return false;
        }
    }
    
    cout << "testCopyOpEq: all passed!" << endl;
    return true;
    
}

bool testClear() {
    BarChart x(2);
    x.addBar("Amaan", 1000, "First");
    x.addBar("Shah", 750, "Last");
    x.setFrame("22");
    
    x.clear();
    
    if (x.getSize() != 0) {
        cout << "testClear: Failed, getsize is not 0" << endl;
        return false;
    } else if (x.getFrame() != "") {
        cout << "testClear: Failed, getFrame is not empty" << endl;
        return false;
    }
    cout << "testClear: all passed!" << endl;
    return true;
}


// barchartanimate.h Tests:
bool testBCAparamConst() {
    string title = "Movie Rankings";
    string xlabel = "tickets sold";
    string source = "";
    
    BarChartAnimate x(title, xlabel, source);
    
    if (x.getSize() != 0) {
        cout << "testBCAparamConst: Failed, size is not 0" << endl;
        return false;
    }
    
    // I also created a temporary public function that I have now delted to confirm the private variables at each index are correct.
    
    cout << "testBCAparamConst: all passed!" << endl;
    return true;
    
}

bool testaddFrame() {
    string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate x(title, xlabel, source);
	
	while (!inFile.eof()) {
		x.addFrame(inFile);
	}
    
    if (x.getSize() != 519) {
        cout << "testaddFrame: Failed, wrong size" << endl;
        return false;
    }
    
    int frameNum = 1500;
    for (int i = 0; i < x.getSize(); i++) {
        string f = x[i].getFrame();
        int num = stoi(f);
        if (num != frameNum) {
            cout << "testaddFrame: Failed, frame is wrong at index " << i << endl;
            return false;
        }
        frameNum++;
    }
    
    cout << "testaddFrame: all passed!" << endl;
    return true;
}

bool testAnimate() {
    string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate x(title, xlabel, source);
	
	while (!inFile.eof()) {
		x.addFrame(inFile);
	}
	
	if (x.getSize() != 519) {
	    cout << endl << "Tests for barchartanimate.h:" << endl;
        cout << "testaddFrame: Failed, wrong size" << endl;
        return false;
    }
    
    x.animate(cout, 12, 1);
    // here i am testing visually to make sure the frame looks
    // just like the one in the handout
    
	cout << endl << "Tests for barchartanimate.h:" << endl;
	cout << "testAnimate: all passed!" << endl;
	return true;
}

bool testgetSize2() {
    string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate x(title, xlabel, source);
	
	if (x.getSize() != 0) {
        cout << "testgetSize2: Failed, wrong size (before adding)" << endl;
        return false;
    }
	
	while (!inFile.eof()) {
		x.addFrame(inFile);
	}
    
    if (x.getSize() != 519) {
        cout << "testgetSize2: Failed, wrong size (after adding)" << endl;
        return false;
    }
    
    cout << "testgetSize2: all passed!" << endl;
    return true;
}

bool testBracketOp2() {
    string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate x(title, xlabel, source);
	
	while (!inFile.eof()) {
		x.addFrame(inFile);
	}
	
	int frame = 1500;
	for (int i = 0; i < x.getSize(); i++) {
	    int f = stoi(x[i].getFrame());
	    if (f != frame) {
	        cout << "testBracketOp2: Failed, wrong frame at index " << i << endl;
	        return false;
	    }
	    frame++;
	}
	
	cout << "testBracketOp2: all passed!" << endl;
	return true;
}

int main() {
    int pass = 0;
    int fail = 0;
    
 	(testAnimate() ? pass++ : fail++);
 	(testBCAparamConst() ? pass++ : fail++);
	(testaddFrame() ? pass++ : fail++);
	(testgetSize2() ? pass++ : fail++);
	(testBracketOp2() ? pass++ : fail++);
	
	cout << endl << "Tests for barchart.h:" << endl;
	(testBarChartDefaultConstructor()) ? pass++ : fail++;
	(testBarChartParamConstructor()) ? pass++ : fail++;
	(testsetFrame()) ? pass++ : fail++;
	(testgetFrame()) ? pass++ : fail++;
	(testaddBar()) ? pass++ : fail++;
	(testgetSize()) ? pass++ : fail++;
	(testBracketOp()) ? pass++ : fail++;
	(testDump()) ? pass++ : fail++;
	(testgraph()) ? pass++ : fail++;
	(testCopyConst()) ? pass++ : fail++;
	(testCopyOpEq()) ? pass++ : fail++;
	(testClear()) ? pass++ : fail++;
	
    cout << endl << "Tests for bar.h:" << endl; 
	(testBarDefaultConstructor()) ? pass++ : fail++;
	(testBarParamConstructor()) ? pass++ : fail++;
	(testLToperator()) ? pass++ : fail++;
	(testLTEoperator()) ? pass++ : fail++;
	(testGToperator()) ? pass++ : fail++;
	(testGTEoperator()) ? pass++ : fail++;
	(testgetName()) ? pass++ : fail++;
	(testgetValue()) ? pass++ : fail++;
	(testgetCategory()) ? pass++ : fail++;
	
	cout << endl << "TEST RESULTS:" << endl;
	cout << "test cases passed: " << pass << endl;
	cout << "test cases failed: " << fail << endl;
    return 0;
}