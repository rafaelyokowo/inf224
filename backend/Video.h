/**
 * @file Video.h
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Class Video
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Video_h
#define Video_h

#include "Media.h"

#include <iostream>
#include <string>

/** @brief Class used to represent a Video. It is a sub class of Media.

    It has, as parameters, the duration of the video
    @author Y., RAFAEL
    @date November 2022
    */
class Video: public Media {
private:
	int duration = 0;

public:
	Video() : Media() {};
	Video(std::string _path, int _duration);
	virtual ~Video();
	void setDuration(int d);
	int getDuration() const;
	void play() override;
	void showTerminal(std::ostream & s) override;
	virtual std::string show() override;
};

Video::Video(std::string _path, int _duration){
	this->setPath(_path);
	duration = _duration;
}

Video::~Video(){
	std::cout << "Destruction d'objet Video" << std::endl;
}

void Video::setDuration(int d) {
	duration = d;
}

int Video::getDuration() const{
	return duration;
}

void Video::play() {
	std::string command;
	command = "mpv " + getPath() +  "&";
	system(command.data());
}

void Video::showTerminal(std::ostream & s){
	s << "Type: " << getType() << std::endl
		<< "Path: "<< getPath() << std::endl
		<< "Duree: " << getDuration() << std::endl;
}

std::string Video::show(){
	return "Type: " + getType() + "@@" + 
		   "Path: " + getPath() + "@@" + 
		   "Duree: " + std::to_string(getDuration()) + "\n";
}

#endif
