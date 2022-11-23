#ifndef Playlist_h
#define Playlist_h

#include "Media.h"

#include <iostream>
#include <string>
#include <list>
#include <memory>

/** @brief Class used to represent a Playlist. It is a sub class of Media.

    It has, as parameter, the group name
    @author Y., RAFAEL
    @date November 2022
    */
class Playlist: public std::list<std::shared_ptr<Media> > {
private:
    std::string groupName;
public:
  Playlist() {};
	Playlist(std::string _groupName);
  ~Playlist() {};
	std::string getName() const;
  template <typename T> void showList(const std::list<T> & l);
};

Playlist::Playlist(std::string _groupName){
    groupName = _groupName;
}

std::string Playlist::getName() const{
	return groupName;
}

template <typename T> void Playlist::showList(const std::list<T> & l) {
    for (auto& it : l){
        it->show(std::cout);
    }
}

#endif
