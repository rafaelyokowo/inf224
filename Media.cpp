#include <iostream>
#include <string>
#include "Media.h"

Media::Media(string _type, string _path){
	type = _type;
	path = _path;
}

void Media::setType(string t){
	type = t;
}
	
string Media::getType() const{
	return type;
}
	
void Media::setPath(std::string p){
	path = p;
}
	
string Media::getPath() const{
	return path;
}

void Media::afficher(std::ostream & s) const{
	s << getType() << " "<< getPath() << std::endl;
}

