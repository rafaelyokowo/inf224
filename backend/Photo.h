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
	Photo(std::string _path, int _latitude, int _longitude);
	virtual ~Photo();
	void setLatitude(int lati);
	void setLongitude(int longi);
	int getLatitude() const;
	int getLongitude() const;
	void play() override;
	void showTerminal(std::ostream & s) override;
	std::string show() override;
};

Photo::Photo(std::string _path, int _latitude, int _longitude){
	this->setPath(_path);
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

void Photo::showTerminal(std::ostream & s){
	s << "Type: " << getType() << std::endl
		<< "Path: "<< getPath() << std::endl
		<< "Latitude: " << getLatitude() << std::endl
		<< "Longitude: " << getLongitude() << std::endl;
}

std::string Photo::show() {
	return "Type: " +  getType() +
		   "Path: " + getPath() +
		   "Latitude: " + std::to_string(getLatitude()) +
		   "Longitude: " + std::to_string(getLongitude());
}

#endif
