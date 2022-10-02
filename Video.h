#ifndef Video_h
#define Video_h

#include <iostream>
#include <string>
#include "Media.h"
using namespace std;

class Video:public Media {
private:
	int duree = 0;

public:
	Video() : Media() {}
	~Video();
	void setDuree(int d);
	int getDuree() const;
	void jouer() override;
	void afficher(std::ostream & s);
};

void Video::setDuree(int d) {
	duree = d;
}

int Video::getDuree() const{
	return duree;
}

void Video::jouer() {
	string command;
	command = "mpv " + getPath() +  "&";
	system(command.data());
}

void Video::afficher(std::ostream & s){
	s << getDuree() << " " << getType() << " "<< getPath() << std::endl;
}

#endif
