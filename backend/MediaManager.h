/**
 * @file MediaManager.h
 * @author Rafael Yuji Yokowo (rafael.yokowo@telecom-paris.fr)
 * @brief Media Management
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MediaManager_h
#define MediaManager_h

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

/** @brief Class used to manage all medias. It is responsible for creating,
 * listing, showing and playing the corresponding medias and their informations

    It has, as parameters, a Media or a Group list
    @author Y., RAFAEL
    @date November 2022
    */
class MediaManager {
private:
    Multimedia multimedia;
    Group group;
public:
    MediaManager() {};
    ~MediaManager() {};
    void createGroup(std::string name);
    FilmType createFilm(std::string name);
    PhotoType createPhoto(std::string name, std::string _path, int latitude, int longitude);
    VideoType createVideo(std::string name, std::string _path, int duration);
    MediaType findMedia(std::string name);
    std::string showMedia(std::string name);
    std::string listMedia();
    std::string listGroup();
    std::string playMedia(std::string name);
    void deleteMedia(std::string name);
    void deleteGroup(std::string name);
};

void MediaManager::createGroup(std::string name) {
   group[name] = std::make_shared<Playlist>();
}

FilmType MediaManager::createFilm(std::string name) {
    multimedia[name] = std::make_shared<Film>();
    multimedia.find(name)->second->setType("Film");
    return std::dynamic_pointer_cast<Film>(multimedia[name]);
}

PhotoType MediaManager::createPhoto(std::string name, std::string _path, int latitude, int longitude) {
    multimedia[name] = std::make_shared<Photo>(_path, latitude, longitude);
    multimedia.find(name)->second->setType("Photo");
    return std::dynamic_pointer_cast<Photo>(multimedia[name]);
}

VideoType MediaManager::createVideo(std::string name, std::string _path, int duration) {
    multimedia[name] = std::make_shared<Video>(_path, duration);
    multimedia.find(name)->second->setType("Video");
    return std::dynamic_pointer_cast<Video>(multimedia[name]);
}

MediaType MediaManager::findMedia(std::string name) {
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

std::string MediaManager::showMedia(std::string name) {
    MediaType media = findMedia(name);
    if (media == nullptr) {
        return "No media named: '" + name +
               "' was found/can be shown.";
    }
    else {
        return media->show();
    }
}

std::string MediaManager::listMedia() {
    std::string list;
    for (auto const& x: this->multimedia){
        list += x.first + "@@";
    }
    return list;
}

std::string MediaManager::listGroup() {
    std::string list;
    for (auto const& x: this->group){
        list += x.first + "@@";
    }
    return list;
}
    
std::string MediaManager::playMedia(std::string name) {
    MediaType media = findMedia(name);
    if (media == nullptr) {
        return "No media named: '" + name +
                "' was found/can be played.";
    }
    else {
        media->play();
        return name + "Played";
    }
}

void MediaManager::deleteMedia(std::string name) {
    if (multimedia.empty() ==  true) {
        std::cout << "Empty list" << std::endl;
    }
    else {
        auto it = multimedia.find(name);
        multimedia.erase(it);
    }
}

void MediaManager::deleteGroup(std::string name) {
    auto it = group.find(name);
    group.erase(it);
}

#endif
