//
// main.cpp
// Created on 21/10/2018
//
#include "stdio.h" 
#include "unistd.h"
#include "Media.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Playlist.h"
#include "GestionMedia.h"
#include "tcpserver.h"

#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string get_working_path()
{
   char temp[200];
   return ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") );
}

const std::string path = get_working_path() + "/";
const int PORT = 3331;

int main(int argc, const char* argv[])
{
	GestionMedia * media = new GestionMedia();

	std::shared_ptr<Video> video = media->createVideo("filme", path + "test.mp4", 10);
	std::shared_ptr<Photo> photo1 = media->createPhoto("telecom", path + "logo.png", 10, 10);
	std::shared_ptr<Photo> photo2 = media->createPhoto("ip-paris", path + "logo-ipparis.png", 10, 10);

	std::cout << media->listMedia();

	// cree le TCPServer
  	auto* server =
  	new TCPServer( [&](std::string const& request, std::string& response) {

  	// the request sent by the client to the server
  	std::cout << "request: " << request << std::endl;

	std::string req = request.substr(0, request.find("-"));
	std::cout << req;
	if (req == "P"){
		media->playMedia(request.substr(2));
	}
	if (req == "S"){
		response = media->showMedia(request.substr(2));
	}
	if (req == "L"){
		std::cout << media->listMedia();
		response = media->listMedia();
	}

	// teste->deleteMedia(request);

  	// the response that the server sends back to the client
  	// response = "RECEIVED: " + request;

  	// return false would close the connecytion with the client
  	return true;
	});

  	// lance la boucle infinie du serveur
  	std::cout << "Starting Server on port " << PORT << std::endl;

  	int status = server->run(PORT);

  	// en cas d'erreur
  	if (status < 0) {
    	std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  	}

    return 0;
}
