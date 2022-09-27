//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Media.h"
#include "Video.h"
#include "Photo.h"

using namespace std;

int main(int argc, const char* argv[])
{
	Video * objet =  new Video();

	objet->setPath("/Users/rafaelyokowo/Desktop/Telecom/INF224/test.mp4");

	string pathname;
	pathname = objet->getPath();
	objet->jouer();
	objet->setDuree(20);
	objet->setType("video");
	objet->afficher(std::cout);

	delete objet;

    std::cout << "Hello brave new world" << std::endl;

    return 0;
}
