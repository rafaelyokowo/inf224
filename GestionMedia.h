#ifndef GestionMedia_h
#define GestionMedia_h

#include "Film.h"
#include "Photo.h"
#include "Playlist.h"

#include <iostream>
#include <string>
#include <memory>
#include <map>

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
    PhotoType createPhoto(std::string name);
    VideoType createVideo(std::string name, int duration);
    MediaType findMedia(std::string name);
    void showMedia(std::string name);
    void playMedia(std::string name);
};

void GestionMedia::createGroup(std::string name) {
   group[name] = std::make_shared<Playlist>();
}

FilmType GestionMedia::createFilm(std::string name) {
    multimedia[name] = std::make_shared<Film>();
    multimedia.find(name)->second->setType("Film");
    return std::dynamic_pointer_cast<Film>(multimedia[name]);
}

PhotoType GestionMedia::createPhoto(std::string name) {
    multimedia[name] = std::make_shared<Photo>();
    multimedia.find(name)->second->setType("Photo");
    return std::dynamic_pointer_cast<Photo>(multimedia[name]);
}

VideoType GestionMedia::createVideo(std::string name, int duration) {
    multimedia[name] = std::make_shared<Video>(duration);
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

void GestionMedia::showMedia(std::string name) {
    MediaType media = findMedia(name);
    if (findMedia(name) == nullptr) {
        std::cout << "No media named: " << name << " was found/can be shown.";
    }
    media->show(std::cout);
}
    
void GestionMedia::playMedia(std::string name) {
    MediaType media = findMedia(name);
    if (findMedia(name) == nullptr) {
        std::cout << "No media named: " << name << " was found/can be played.";
    }
    media->play();
}



#endif
