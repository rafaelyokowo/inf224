//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Media.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"

using namespace std;

int main(int argc, const char* argv[])
{
	int s = 2;
	int * tableau = new int[s]{10,20};
	Film * newFilm = new Film();
	newFilm->setTableau(tableau);
	newFilm->afficher(s);

	const int * copie = newFilm->getTableau();
	for (int i = 0; i < s; i++){
        cout << copie[i] << " ";
	}
	cout << endl;

	int * tableau2 = new int[s]{100,300};
	newFilm->setTableau(tableau2);
	newFilm->afficher(s);

	delete newFilm;

	for (int i = 0; i < s; i++){
        cout << copie[i] << " ";
	}
	cout << endl;


    //Media * playlist[s];
	//playlist[0] = new Video();
	//playlist[1] = new Photo();
	//playlist[0]->setPath("/cal/exterieurs/ryokowo-22/Desktop/inf224/test.mp4");
	//playlist[1]->setPath("/cal/exterieurs/ryokowo-22/Desktop/inf224/logo.png");

	//playlist[0]->jouer();
	//playlist[1]->jouer();

	//for (int i=0; i < s; i++){
    //    delete playlist[i];
	//}


    // std::cout << "Hello brave new world" << std::endl;

    return 0;
}
