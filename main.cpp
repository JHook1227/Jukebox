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
    void print_playlists() const {
    cout << "Playlists in Jukebox:" << endl;
    for (const Genre& genre : genres) {
        cout << "Genre: " << genre.name << endl;
        for (const Playlist& playlist : genre.playlists) {
            cout << "  Playlist: " << playlist.name << endl;
            for (const Song& song : playlist.songs) {
                cout << "    Song: " << song.title << " by " << song.artist << endl;
            }
        }
    }
}
    //void Jukebox::press_play() {
    //const Song& curr_song = get_curr_song();
    //cout << curr_song.title << " by " << curr_song.artist << " is playing. " << endl;

    //if (isonrepeat) {
        //press_play();
    //} else {
        //if (curr_song_idx + 1 < genres[curr_genre_idx].playlists[curr_playlist_idx].songs.size()) {
            //curr_song_idx++;
            //press_play();
        //} else if (curr_playlist_idx + 1 < genres[curr_genre_idx].playlists.size()) {
            //skip_to_first_track_next_playlist();
            //press_play();
        //} else {
            //restart_jukebox();
        //}
    //}
//}
            

                                          
};
int main() {
    
    Jukebox jukebox;
    Genre genre1;
    genre1.name = "Rock";

    Genre genre2;
    genre2.name = "Pop";

    jukebox.genres.push_back(genre1);
    jukebox.genres.push_back(genre2);

    Playlist playlist1;
    playlist1.name = "Classic Rock";
    playlist1.songs.push_back({"Stairway to Heaven", "Led Zeppelin"});
    playlist1.songs.push_back({"Bohemian Rhapsody", "Queen"});

    Playlist playlist2;
    playlist2.name = "Top Hits";
    playlist2.songs.push_back({"Shape of You", "Ed Sheeran"});
    playlist2.songs.push_back({"Blinding Lights", "The Weeknd"});

    jukebox.genres[0].playlists.push_back(playlist1);
    jukebox.genres[1].playlists.push_back(playlist2);
    
    jukebox.print_playlists();
    
    return 0;
}
     


    

    
    
    

