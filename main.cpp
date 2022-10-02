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
	int size = 2;
	Media * playlist[size];
	playlist[0] = new Video();
	playlist[1] = new Photo();
	playlist[0]->setPath("/Users/rafaelyokowo/Desktop/Telecom/INF224/test.mp4");
	playlist[1]->setPath("/Users/rafaelyokowo/Desktop/Telecom/INF224/logo.png");

	playlist[0]->jouer();
	playlist[1]->jouer();

	for (int i=0; i < size; i++){
		delete playlist[i];
	}


    // std::cout << "Hello brave new world" << std::endl;

    return 0;
}
