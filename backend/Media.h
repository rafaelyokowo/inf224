#ifndef Media_h
#define Media_h
#include <iostream>
#include <string>

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
