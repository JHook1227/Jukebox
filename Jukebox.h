#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

struct Song { //song struct
    string title;
    string artist;
};

struct Genres {
    vector <Playlist> playlists;
    string name;
};

struct Playlist {
    string name;
    vector<Song> songs;
};
struct Jukebox {
    vector <Genres> genres;
    int curr_genre_idx;
    int curr_playlist_idx;
    int curr_song_idx;
    bool isplaying;
    bool isonrepeat;
    
    Jukebox() : curr_genre_idx(0), curr_playlist_idx(0), curr_song_idx(0), isplaying(false), isonrepeat(false){}
    
    void play_pause(){
        isplaying = !isPlaying;
    
    void addgenre(Genre& add_genre){
        genre.push_back(add_genre);
        cout << add_genre << " added  to playlist.";
    }
        
    void skip_to_prev(){
        if (curr_song_idx > 0){
            curr_song_idx--;
            //
    void addsongtogenre(string genrename, Song* new_song){
        for(Genre* genre : genres){
            if(genre.name == genrename){
                genre.addsongtogenre(new_song);
                cout << new_song << " added to " << genrename;
                }
            else{
                addgenretoplaylist(genrename);
                genrename.addsongtogenre(new_song);
            }
        }
    }
    void play(
        
};


    

    
    
    

