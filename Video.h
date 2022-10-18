#ifndef Video_h
#define Video_h

#include "Media.h"

#include <iostream>
#include <string>

class Video: public Media {
private:
	int duration = 0;

public:
	Video() : Media() {}
	Video(int _duration);
	~Video();
	void setDuration(int d);
	int getDuration() const;
	void play() override;
	void show(std::ostream & s) override;
};

Video::Video(int _duration){
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

void Video::show(std::ostream & s){
	s << "Type: " << getType() << std::endl
		<< "Path: "<< getPath() << std::endl
		<< "Duree: " << getDuration() << std::endl;
}

#endif
