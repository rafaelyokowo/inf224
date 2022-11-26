/**
 * @file Media.cpp
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Class Media implementation file
 * @version 1.0
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Media.h"

#include <iostream>
#include <string>

Media::Media(std::string _type, std::string _path){
	std::string type = _type;
	std::string path = _path;
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

void Media::showTerminal(std::ostream & s){
	s << "Type: " << getType() << std::endl
	  << "Path: " << getPath() << std::endl;
}

std::string Media::show(){
	return "Type: " + getType() +
		   "Path: " + getPath();
}
