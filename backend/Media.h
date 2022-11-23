/**
 * @file Media.h
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Super Class Media
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef Media_h
#define Media_h
#include <iostream>
#include <string>

/** @brief Class used to represent a media. It is the super class of 
 *  all types of medias.

    It has, as parameters, the file's type and path
    @author Y., RAFAEL
    @date November 2022
    */
class Media {
private:
	std::string type = "foo";
	std::string path = "bar";

public:
	Media() {};
	Media(std::string _type, std::string _path);
	~Media() {};
	void setType(std::string t);
	std::string getType() const;
	void setPath(std::string p);
	std::string getPath() const;
	virtual void play();
	virtual void showTerminal(std::ostream & s);
	virtual std::string show();
};

#endif
