#ifndef Video_h
#define Video_h

#include "Media.h"

#include <iostream>
#include <string>

		<< " " << getType() << " "<< getPath() << std::endl;
class Video: public Media {
private:
	int duree = 0;

public:
	Video() : Media() {}
	Video(int _duree);
	~Video();
	void setDuree(int d);
	int getDuree() const;
	void play() override;
	void show(std::ostream & s) override;
};

Video::Video(int _duree){
	duree = _duree;
}

Video::~Video(){
	std::cout << "Destruction d'objet Video" << std::endl;
}

void Video::setDuree(int d) {
	duree = d;
}

int Video::getDuree() const{
	return duree;
}

void Video::play() {
	std::string command;
	command = "mpv " + getPath() +  "&";
	system(command.data());
}

void Video::show(std::ostream & s){
	s << "Type: " << getType() << std::endl
		<< "Path: "<< getPath() << std::endl
		<< "Duree: " << getDuree() << std::endl;
}

#endif
