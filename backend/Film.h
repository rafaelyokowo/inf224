#ifndef Film_h
#define Film_h

#include "Video.h"

#include <iostream>
#include <algorithm>
#include <string>

class Film: public Video {
private:
  int arraySize = 0;
  int * durationArray = nullptr;

public:
	Film() : Video() {};
	Film(int _arraySize, int * _durationArray);
	virtual ~Film();
	void setArray(int * t, int size);
	const int * getArray() const;
	const int getSize() const;
	std::string show() override;
};

Film::Film(int _arraySize, int * _durationArray){
	arraySize = _arraySize;
	durationArray = _durationArray;
}

Film::~Film(){
	delete [] durationArray;
	std::cout << "Destruction d'objet Film" << std::endl;
}

void Film::setArray(int * t, int size) {
	if(durationArray != nullptr) delete [] durationArray;

  if(t == nullptr){
    arraySize = 0;
    durationArray = t;
  }
  else {
    arraySize = size;
  	durationArray = new int[arraySize];
  	for (int i = 0; i < arraySize; i++){
         durationArray[i] = t[i];
  	}
  }
}

const int * Film::getArray() const{
  int * t = new int[arraySize];
	for (int i = 0; i < arraySize; i++){
       t[i] = durationArray[i];
	}
	return t;
}

const int Film::getSize() const{
	return arraySize;
}

std::string Film::show(){
	std::string durations;
    for(int i = 0; i < sizeof(durationArray); i++){
		durations += std::to_string(durationArray[i]) + " ";
    }
    return durations;
}


#endif
