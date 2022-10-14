#ifndef Playlist_h
#define Playlist_h

#include <iostream>
#include <string>
#include <list>
#include "Media.h"
using namespace std;

class Playlist: list<shared_ptr<Media>> {
private:
    string groupName;

public:
    Playlist();
	Playlist(string _groupName);
    ~Playlist() {};
	string getName() const;
	void show(int t);
};

Playlist::Playlist(string _groupName){
    groupName = _groupName;
}

string Playlist::getName() const{
	return groupName;
}

void Playlist::show(int t){
    for(int i = 0; i < t; i++){
    }
    cout << endl;
}

#endif
