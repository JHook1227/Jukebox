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
        Genre& curr_genre = genres[curr_genre_idx];
        Playlist& curr_playlist = curr_genre.playlists[curr_playlist_idx];
        Song& curr_song = curr_playlist.songs[curr_song_idx];
        if (isplaying == true){
            cout << curr_song.title << " by " << curr_song.artist << " is playing." << endl;
        }
        else{
            cout << "Paused." << endl;
    }
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
    cout << "Jukebox:" << endl;
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
    size_t get_current_playlist_index() {
        return curr_playlist_idx;
    }
    //void press_play() {
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
    int choice;
    
    
    do {
        cout << "1. Play/Pause" << endl;
        cout << "2. Skip to Previous Track" << endl;
        cout << "3. Skip to Next Track" << endl;
        cout << "4. Skip to First Track of Current Playlist" << endl;
        cout << "5. Skip to First Track of Previous Playlist" << endl;
        cout << "6. Skip to First Track of Next Playlist" << endl;
        cout << "7. Rearrange Playlists" << endl;
        cout << "8. Toggle Repeat" << endl;
        cout << "9. Create Genre" << endl;
        cout << "10. Create Playlist" << endl;
        cout << "11. Add song to Playlist" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        
        switch (choice) {
            case 1:
                jukebox.play_pause();
                break;
            case 2:
                jukebox.skip_to_prev_track();
                break;
            case 3:
                jukebox.skip_to_next_track();
                break;
            case 4:
                jukebox.skip_to_first_track_curr_playlist();
                break;
            case 5:
                jukebox.skip_to_first_track_prev_playlist();
                break;
            case 6:
                jukebox.skip_to_first_track_next_playlist();
                break;
            case 7:
                size_t new_idx;
                cout << "Choose a new spot for the current playlist from 1 to " << jukebox.genres.size() << endl;
                cin >> new_idx;
                jukebox.rearrange_playlists(jukebox.get_current_playlist_index(), new_idx);
                cout << "Playlist rearranged" << endl;
                break;
            case 8:
                jukebox.repeat();
                break;
            case 9:
                {
                string genre_name;
                cout << "Enter genre name: ";
                cin.ignore();
                getline(cin, genre_name);
                Genre genre;
                genre.name = genre_name;
                jukebox.genres.push_back(genre);
                cout << "Genre created: " << genre_name << endl;
                    }
                break;
            case 10:
                        {
                            string genre_name;
                            cout << "Enter genre name: ";
                            cin.ignore();
                            getline(cin, genre_name);
                            for (Genre& genre : jukebox.genres){
                                if (genre.name == genre_name){
                                    string playlist_name;
                                    cout << "Enter playlist name: ";
                                    getline(cin, playlist_name);
                                    Playlist playlist;
                                    playlist.name = playlist_name;
                                    genre.playlists.push_back(playlist);
                                    cout << "Playlist created: " << playlist_name << endl;
                                    break;
                                }
                                else{
                                    cout << "Invalid genre name, please add genre." << endl;
                            }
                        }
                break;
            case 11: 
                {
                    string genre_name, playlist_name;
                    cout << "Enter genre name: ";
                    cin.ignore();
                    getline(cin, genre_name);
                    cout << "Enter playlist name: ";
                    getline(cin, playlist_name);
                    for (Genre& genre : jukebox.genres){
                        if (genre.name == genre_name){
                            for (Playlist& playlist : genre.playlists){
                                if (playlist.name == playlist_name){
                                    string song_title, song_artist;
                                    cout << "Enter song title: ";
                                    getline(cin, song_title);
                                    cout << "Enter song artist: ";
                                    getline(cin, song_artist);
                                    Song song;
                                    song.title = song_title;
                                    song.artist = song_artist;
                                    playlist.songs.push_back(song);
                                    cout << song_title << " by " << song_artist << " added to " << playlist_name << " in " << genre_name << endl;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                    break;
            case 12:
                cout << "Exiting" << endl;
                jukebox.print_playlists();
                return 0;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }while (true);
    
    return 0;
}
     


    

    
    
    

