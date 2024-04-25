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
    vector<Genre> genres;
    int curr_genre_idx;
    int curr_playlist_idx;
    int curr_song_idx;
    bool isplaying;
    bool isonrepeat;
    
    Jukebox() : curr_genre_idx(0), curr_playlist_idx(0), curr_song_idx(0), isplaying(false), isonrepeat(false){}
    
    void play_pause(){
        isplaying = !isPlaying;
    }
    
    void repeat(){
        isonrepeat = !isonrepeat;
    }
    
    void addgenre(Genre& add_genre){
        genre.push_back(add_genre);
        cout << add_genre << " added  to playlist.";
    }
        
    
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
    void skip_to_prev_track(){
        if (curr_song_idx > 0){
            curr_song_idx--;
        }
        else if (curr_playlist_idx > 0){
            curr_playlist_idx--;
            curr_song_idx = 0;
        }
        else if (curr_genre_idx > 0){
            curr_genre_idx--;
            curr_playlist_idx = 0;
            curr_song_idx = 0;
        }
    }
    void skip_to_next_track(){
        Genre* curr_genre = genres[curr_genre_idx];
        Playlist* curr_playlist = playlists[curr_playlist_idx];
        if (curr_song_idx < songs.size() - 1){
            curr_song_idx++;
        }
        else if (curr_playlist_idx < curr_genre.playlists.size() - 1){
            curr_playlist_idx++;
            curr_song_idx = 0;
        }
        else if (curr_genre_idx < genres.size() - 1){
            curr_genre_idx++;
            curr_playlist_idx = 0;
            curr_song_idx = 0;
        }
        else if (isonrepeat){
            curr_song_idx = 0;
        }
    }
    void skip_to_first_track_curr_playlist(){
        curr_song_idx = 0;
    }
    void skip_to_first_track_prev_playlist(){
        if (curr_playlist_idx > 0){
            curr_playlist_idx--;
            curr_song_idx = 0;
        }
        else if (curr_genre_idx > 0){
            curr_genre_idx--;
            curr_playlist_idx = 0;
            curr_song_idx = 0;
        }
        else{
            curr_genre_idx = genres.size() - 1;
            curr_playlist_idx = 0;
            curr_song_idx = 0;
        }
    }
    void skip_to_first_track_next_playlist(){
        Genre* curr_genre = genres[curr_genre_idx];
        if (curr_playlist_idx < curr_genre.playlist.size() - 1){
            curr_playlist_idx++;
            curr_song_idx = 0;
        }
    }
    
            
    Genre* rearrange_playlists(int curr_genre_idx, int curr_song_idx, int curr_playlist_idx){
        
        
                
                
        
};


    

    
    
    

