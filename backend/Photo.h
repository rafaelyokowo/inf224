/**
 * @file Photo.h
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Class Photo
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Photo_h
#define Photo_h

#include "Media.h"

#include <iostream>
#include <string>

/** @brief Class used to represent a Photo. It is a sub class of Media.

    It has, as parameters, the latitude and longitude of the photo
    @author Y., RAFAEL
    @date November 2022
    */
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
	command = "imagej " + getPath() +  "&";
	system(command.data());
}

void Photo::showTerminal(std::ostream & s){
	s << "Type: " << getType() << std::endl
		<< "Path: "<< getPath() << std::endl
		<< "Latitude: " << getLatitude() << std::endl
		<< "Longitude: " << getLongitude() << std::endl;
}

std::string Photo::show() {
	return "Type: " +  getType() + "@@" +
		   "Path: " + getPath() + "@@" +
		   "Latitude: " + std::to_string(getLatitude()) + "@@" +
		   "Longitude: " + std::to_string(getLongitude());
}

#endif
