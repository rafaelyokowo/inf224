#ifndef Photo_h
#define Photo_h

#include "Media.h"

#include <iostream>
#include <string>

class Photo: public Media {
private:
	int latitude = 0;
	int longitude = 0;

public:
	Photo() : Media() {};
	Photo(int _latitude, int _logitude);
	virtual ~Photo();
	void setLatitude(int lati);
	void setLongitude(int longi);
	int getLatitude() const;
	int getLongitude() const;
	void play() override;
	void show(std::ostream & s) override;
};

Photo::Photo(int _latitude, int _longitude){
	latitude = _latitude;
	longitude = _longitude;
}

Photo::~Photo(){
	std::cout << "Destruction d'objet Photo" << std::endl;
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

void Photo::play() {
	std::string command;
	command = "qlmanage -p " + getPath() +  "&";
	system(command.data());
}

void Photo::show(std::ostream & s){
	s << "Type: " << getType() << std::endl
		<< "Path: "<< getPath() << std::endl
		<< "Latitude: " << getLatitude() << std::endl
		<< "Longitude: " << getLongitude() << std::endl;
}

#endif
