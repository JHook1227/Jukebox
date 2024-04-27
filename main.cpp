#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

struct Song { //song struct
    string title;
    string artist;
};

struct Playlist {
    string name;
    vector<Song> songs;
};

struct Genre {
    vector<Playlist> playlists;
    string name;
    
};


struct Jukebox {
    vector<Genre> genres;
    size_t curr_genre_idx;
    size_t curr_playlist_idx;
    size_t curr_song_idx;
    bool isplaying;
    bool isonrepeat;
    
    Jukebox() : curr_genre_idx(0), curr_playlist_idx(0), curr_song_idx(0), isplaying(false), isonrepeat(false){}
    
    void play_pause(){
        isplaying = !isplaying;
    }
    
    void repeat(){
        isonrepeat = !isonrepeat;
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
        Genre& curr_genre = genres[curr_genre_idx];
        Playlist& curr_playlist = curr_genre.playlists[curr_playlist_idx];
        if (curr_song_idx < curr_playlist.songs.size() - 1){
            ++curr_song_idx;
        }
        else if (curr_playlist_idx < curr_genre.playlists.size() - 1){
            ++curr_playlist_idx;
            curr_song_idx = 0;
        }
        else if (curr_genre_idx < genres.size() - 1){
            ++curr_genre_idx;
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
        Genre& curr_genre = genres[curr_genre_idx];
        if (curr_playlist_idx < curr_genre.playlists.size() - 1){
            curr_playlist_idx++;
            curr_song_idx = 0;
        }
    }
    
            
    void rearrange_playlists(size_t curr_genre_idx, size_t new_genre_idx){
        if (curr_genre_idx < genres.size() && new_genre_idx < genres.size()){
            size_t temp = genres.size() + 1;
            genres[temp] = genres[new_genre_idx];
            genres[new_genre_idx] = genres[curr_genre_idx];
            genres[curr_genre_idx] = genres[temp];
            genres.erase(genres.begin() + temp);
        }
    }
    void restart_jukebox(){
        curr_genre_idx = 0;
        curr_song_idx = 0;
        curr_playlist_idx = 0;
    }
            
    void press_play(){
        const Song& curr_song = get_curr_song();
        cout << curr_song.title << " by " << curr_song.artist << " is playing. " << endl;
        if (isonrepeat && curr_song_idx + 1 >= genres[curr_genre_idx].playlists[curr_playlist_idx].songs.size()){
            press_play();
        }
        else if (curr_song_idx + 1 < genres[curr_genre_idx].playlists[curr_playlist_idx].songs.size()){
              curr_song_idx++;
              press_play();
            }
        else if(curr_playlist_idx < genres[curr_genre_idx].playlists.size()){
              skip_to_first_track_next_playlist();
              press_play();
        }
        else{
            restart_jukebox();
        }
    }
                                               
    const Song& get_curr_song() const {
        const Genre& curr_genre = genres[curr_genre_idx];
        const Playlist& curr_playlist = curr_genre.playlists[curr_playlist_idx];
        const Song& curr_song = curr_playlist.songs[curr_song_idx];
        return curr_song;
    }
                                          
};
int main() {
Jukebox jukebox;

    Genre genre1;
    genre1.name = "Rock";
    Playlist playlist1;
    playlist1.name = "Classic Rock";
    playlist1.songs = {{"Stairway to Heaven", "Led Zeppelin"}, {"Bohemian Rhapsody", "Queen"}};
    genre1.playlists.push_back(playlist1);

    Genre genre2;
    genre2.name = "Pop";
    Playlist playlist2;
    playlist2.name = "Top Hits";
    playlist2.songs = {{"Shape of You", "Ed Sheeran"}, {"Blinding Lights", "The Weeknd"}};
    genre2.playlists.push_back(playlist2);
    jukebox.press_play();
    return 0;
}
     


    

    
    
    

