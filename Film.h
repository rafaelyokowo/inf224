#ifndef Film_h
#define Film_h

#include <iostream>
#include <algorithm>
#include <string>
#include "Video.h"
using namespace std;

class Film:public Video {
private:
    int arraySize = 0;
	int * durationArray = nullptr;

public:
	Film() : Video() {}
	Film(int _arraySize, int * _durationArray);
    ~Film() {};
	void setArray(int * t, int size);
	const int * getArray() const;
	const int getSize() const;
	void show(int t);
};

Film::Film(int _arraySize, int * _durationArray){
	arraySize = _arraySize;
	durationArray = _durationArray;
}

void Film::setArray(int * t, int size) {
	if(durationArray != nullptr) delete [] durationArray;

	// durationArray = new int[size];
	// for (int i = 0; i < size; i++){
    //    durationArray[i] = t[i];
	//}
}

const int * Film::getArray() const{
	return durationArray;
}

const int Film::getSize() const{
	return arraySize;
}

void Film::show(int t){
    for(int i = 0; i < t; i++){
        cout << durationArray[i] << " ";
    }
    cout << endl;
}

#endif
