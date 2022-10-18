#include "Media.h"

#include <iostream>
#include <string>

Media::Media(std::string _type, std::string _path){
	type = _type;
	path = _path;
}

void Media::setType(std::string t){
	type = t;
}

std::string Media::getType() const{
	return type;
}

void Media::setPath(std::string p){
	path = p;
}

std::string Media::getPath() const{
	return path;
}

void Media::play() {
	return;
}

void Media::show(std::ostream & s){
	s << "Type: " << getType() 
		<< "Path: "<< getPath() << std::endl;
}
