#ifndef GestionMedia_h
#define GestionMedia_h

#include "Media.h"
#include "Playlist.h"

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <map>

typedef std::map<std::shared_ptr<Media> > Multimedia;
typedef std::map<std::shared_ptr<Playlist> > Groupe;

class GestionMedia {
private:
    Multimedia multimedia = nullptr;
    Groupe groupe = nullptr;
public:
    GestionMedia();
    ~GestionMedia() {};
};

#endif
