#ifndef Photo_h
#define Photo_h

#include <iostream>
#include <string>
#include "Media.h"
using namespace std;

class Photo:public Media {
private:
	int latitude = 0;
	int longitude = 0;

public:
	Photo() : Media() {}
	Photo(int _latitude, int _logitude);
	~Photo() {};
	void setLatitude(int lati);
	void setLongitude(int longi);
	int getLatitude() const;
	int getLongitude() const;
	void jouer() override;
	void afficher(std::ostream & s);
};

Photo::Photo(int _latitude, int _longitude){
	latitude = _latitude;
	longitude = _longitude;
}

void Photo::setLatitude(int lati) {
	latitude = lati;
}

void Photo::setLongitude(int longi){
	longitude = longi;
}

int Photo::getLatitude() const{
	return latitude;
}

int Photo::getLongitude() const{
	return longitude;
}

void Photo::jouer() {
	string command;
	command = "qlmanage -p " + getPath() +  "&";
	system(command.data());
}

void Photo::afficher(std::ostream & s){
	s << getLatitude() << " " << getLongitude() << " " << getType() 
	<< " "<< getPath() << std::endl;
}

#endif
