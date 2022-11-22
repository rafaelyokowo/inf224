#ifndef GestionMedia_h
#define GestionMedia_h

#include "Film.h"
#include "Photo.h"
#include "Playlist.h"

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>

typedef std::map<std::string, std::shared_ptr<Media> > Multimedia;
typedef std::map<std::string, std::shared_ptr<Playlist> > Group;

typedef std::shared_ptr<Film> FilmType;
typedef std::shared_ptr<Media> MediaType;
typedef std::shared_ptr<Photo> PhotoType;
typedef std::shared_ptr<Video> VideoType;

class GestionMedia {
private:
    Multimedia multimedia;
    Group group;
public:
    GestionMedia() {};
    ~GestionMedia() {};
    void createGroup(std::string name);
    FilmType createFilm(std::string name);
    PhotoType createPhoto(std::string name, std::string _path, int latitude, int longitude);
    VideoType createVideo(std::string name, std::string _path, int duration);
    MediaType findMedia(std::string name);
    // void showMedia(std::string name);
    std::string showMedia(std::string name);
    std::string listMedia();
    std::string listGroup();
    void playMedia(std::string name);
    void deleteMedia(std::string name);
    void deleteGroup(std::string name);

};

void GestionMedia::createGroup(std::string name) {
   group[name] = std::make_shared<Playlist>();
}

FilmType GestionMedia::createFilm(std::string name) {
    multimedia[name] = std::make_shared<Film>();
    multimedia.find(name)->second->setType("Film");
    return std::dynamic_pointer_cast<Film>(multimedia[name]);
}

PhotoType GestionMedia::createPhoto(std::string name, std::string _path, int latitude, int longitude) {
    multimedia[name] = std::make_shared<Photo>(_path, latitude, longitude);
    multimedia.find(name)->second->setType("Photo");
    return std::dynamic_pointer_cast<Photo>(multimedia[name]);
}

VideoType GestionMedia::createVideo(std::string name, std::string _path, int duration) {
    multimedia[name] = std::make_shared<Video>(_path, duration);
    multimedia.find(name)->second->setType("Video");
    return std::dynamic_pointer_cast<Video>(multimedia[name]);
}

MediaType GestionMedia::findMedia(std::string name) {
    if (multimedia.empty() ==  true) {
        return nullptr;
    }
    auto it = multimedia.find(name);
    if (it != multimedia.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

std::string GestionMedia::showMedia(std::string name) {
    MediaType media = findMedia(name);
    if (media == nullptr) {
        return "No media named: '" + name +
               "' was found/can be shown.";
    }
    else {
        return media->show();
    }
}

std::string GestionMedia::listMedia() {
    std::string list;
    for (auto const& x: this->multimedia){
        list += x.first + "@@";
    }
    return list;
}

std::string GestionMedia::listGroup() {
    std::string list;
    for (auto const& x: this->group){
        list += x.first + "@@";
    }
    return list;
}
    
void GestionMedia::playMedia(std::string name) {
    MediaType media = findMedia(name);
    if (media == nullptr) {
        std::cout << "No media named: '" << name 
                    << "' was found/can be played." << std::endl;
    }
    else {
        media->play();
    }
}

void GestionMedia::deleteMedia(std::string name) {
    if (multimedia.empty() ==  true) {
        std::cout << "Empty list" << std::endl;
    }
    else {
        auto it = multimedia.find(name);
        multimedia.erase(it);
    }
}

void GestionMedia::deleteGroup(std::string name) {
    auto it = group.find(name);
    group.erase(it);
}

#endif
