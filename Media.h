#ifndef Media_h
#define Media_h
#include <iostream>
#include <string>
using namespace std;

class Media {
private:
	string type{};
	string path{};

public:
	Media() {};
	//~Media();
	Media(string t, string p);
	void setType(string t);
	string getType() const;
	void setPath(string p);
	string getPath() const;
	void jouer() const;
	void afficher(std::ostream & s) const;
};
#endif
