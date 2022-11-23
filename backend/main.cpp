/**
 * @file main.cpp
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Project's backend main file 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "stdio.h" 
#include "unistd.h"
#include "Media.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Playlist.h"
#include "MediaManager.h"
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
	MediaManager * media = new MediaManager();
	MediaManager * group = new MediaManager();

	group->createGroup("Group-A");
	group->createGroup("Group-B");
	group->createGroup("Group-C");

	std::shared_ptr<Video> video = media->createVideo("Video", path + "test.mp4", 10);
	std::shared_ptr<Photo> photo1 = media->createPhoto("Logo-Telecom", path + "logo.png", 10, 10);
	std::shared_ptr<Photo> photo2 = media->createPhoto("Logo-IP-Paris", path + "logo-ipparis.png", 10, 10);

	// cree le TCPServer
  	auto* server =
  	new TCPServer( [&](std::string const& request, std::string& response) {

  	// the request sent by the client to the server
	std::string req = request.substr(0, request.find("-"));

	// the responses that the server sends back to the client
	if (req == "P"){
		response = media->playMedia(request.substr(2));
	}
	if (req == "S"){
		response = media->showMedia(request.substr(2));
	}
	if (req == "LM"){
		response = media->listMedia();
	}
	if (req == "LG"){
		response = group->listGroup();
	}

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
