//
// main.cpp
// Created on 21/10/2018
//
#include "Media.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Playlist.h"

#include <iostream>
#include <memory>

std::string macPath = "/Users/rafaelyokowo/Desktop/Telecom/inf224/";
std::string debianPath = "/cal/exterieurs/ryokowo-22/Desktop/inf224/";

int main(int argc, const char* argv[])
{
	// std::string name = "memorias";
	// std::string name2 = "memorias2";
	
	// Playlist * lista = new Playlist(name);
	// Playlist * lista2 = new Playlist(name2);
	
	// std::shared_ptr<Video> video = std::make_shared<Video>(10);
	// std::shared_ptr<Photo> photo = std::make_shared<Photo>(50000,50000);
	
	// video->setPath(macPath + "test.mp4");
	// video->setType("video");
	
	// photo->setPath(macPath + "logo.png");
	// photo->setType("photo");
	
	// lista->push_back(video);
	// lista->push_back(photo);
	
	// lista->showList(*lista);
	
	// for (auto & it : *lista) {
	// 	//it->play();
	// 	it.reset();
	// }

	// lista2->push_back(video);
	// lista2->push_back(photo);

	// for (auto & it : *lista2) {
	// 	it->play();
	// 	it.reset();
	// }
	

	int s = 4;
	int * tableau = new int[s]{10, 20, 30, 40};
	Film * newFilm = new Film(s, tableau);
	newFilm->show(s);

	const int * read = newFilm->getArray();
	for (int i = 0; i < s; i++){
        std::cout << read[i] << " ";
	}
	std::cout << std::endl;

	int * tableau2 = new int[s]{11, 22, 33, 44};
	newFilm->setArray(tableau2, s);
	newFilm->show(s);

	for (int i = 0; i < s; i++){
        std::cout << read[i] << " ";
	}
	std::cout << std::endl;

	int * teste = new int();
	delete teste;

    // Media * playlist[s];
	// playlist[0] = new Video();
	// playlist[1] = new Photo(50000,50000);
	// playlist[0]->setPath(macPath + "test.mp4");
	// playlist[1]->setPath(macPath + "logo.png");

	// playlist[1]->afficher(cout);

	// //playlist[0]->play();
	// //playlist[1]->play();

	// for (int i=0; i < s; i++){
    //     delete playlist[i];
	// }


    // std::cout << "Hello brave new world" << std::endl;

    return 0;
}
