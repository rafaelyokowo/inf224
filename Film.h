#ifndef Film_h
#define Film_h

#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

class Film:public Video {
private:
    int tailleTableau = 0;
	int * tableauDuree = nullptr;

public:
	Film() : Video() {}
    ~Film();
	void setTableau(int * t);
	const int * getTableau() const;
	const int getTaille() const;
	void afficher(int t);
};

void Film::setTableau(int * t) {
	tableauDuree = t;
}

const int * Film::getTableau() const{
	return tableauDuree;
}

const int Film::getTaille() const{
	return tailleTableau;
}

void Film::afficher(int t){
    for(int i = 0; i < t; i++){
        cout << tableauDuree[i] << " ";
    }
    cout << endl;
}

#endif
