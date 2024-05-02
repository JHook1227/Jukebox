# Jukebox

Data Structure: Vectors

Vectors are dynamic arrays that resizes itslf as elements are added to it. Elements are stored as an indexed list and allows for constant time access to elements. I chose vectors for the jukebox because it came to mind immediately when I thought about the organization of a playlist and  accessing the elements through indices seemed like an efficient way to manage and move the data stored within the lists.

How to: With the files provided simply cmake .. and make in the terminal then ./run_app. The code should prompt you with a menu of options. Since the structs are embedded within each other you'll need to input a Genre, then a Playlist within the Genre, and finally add song to the playlist you created. If you attempt these steps out of sequence you should get a prompt that tells you what you did wrong and how to remedy it. If you forget the names of the playlists and/or genres you can print out the content of the jukebox. 
