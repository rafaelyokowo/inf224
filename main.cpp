//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Media.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Playlist.h"

using namespace std;

string macPath = "/Users/rafaelyokowo/Desktop/Telecom/inf224/";
string debianPath = "/cal/exterieurs/ryokowo-22/Desktop/inf224/";

int main(int argc, const char* argv[])
{
	string name = "memorias";
	Playlist * lista = new Playlist(name);

	// list<Media *> lista1;

	// lista->push_back(make_shared<Video>(10));
	// lista->push_back(make_shared<Photo>(50000,50000));


	// int s = 4;
	// int * tableau = new int[s]{10, 20, 30, 40};
	// Film * newFilm = new Film(s, tableau);
	// newFilm->show(s);

	// int * read = new int[s]{*newFilm->getArray()};
	// for (int i = 0; i < s; i++){
    //     cout << read[i] << " ";
	// }
	// cout << endl;

	// int * tableau2 = new int[s]{11, 22, 33, 44};
	// newFilm->setArray(tableau2, s);
	// newFilm->show(s);

	// for (int i = 0; i < s; i++){
    //     cout << read[i] << " ";
	// }
	// cout << endl;

	// int * teste = new int();
	// delete teste;


    // Media * playlist[s];
	// playlist[0] = new Video();
	// playlist[1] = new Photo(50000,50000);
	// playlist[0]->setPath(macPath + "test.mp4");
	// playlist[1]->setPath(macPath + "logo.png");

	// playlist[1]->afficher(cout);

	// //playlist[0]->jouer();
	// //playlist[1]->jouer();

	// for (int i=0; i < s; i++){
    //     delete playlist[i];
	// }


    // std::cout << "Hello brave new world" << std::endl;

    return 0;
}
