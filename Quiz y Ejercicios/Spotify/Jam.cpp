#include <iostream>
#include <string>
#include <list>

using namespace std;

class Playlist
{
private:
    string name;
    list<string> songs;

public:
    Playlist(string name)
    {
        this->name = name;
    }
    ~Playlist() {}
    void addSong(string song)
    {
        this->songs.push_back(song);
    }
    void removeSong(string song)
    {
        this->songs.remove(song);
    }
    void showSongs()
    {
        for (auto &song : this->songs)
        {
            cout << song << endl;
        }
    }
    string getName()
    {
        return this->name;
    }
    bool operator==(const Playlist &other) const
    {
        return name == other.name;
    }
};

class Jam
{
private:
    list<Playlist> playlists;

public:
    Jam() {}
    ~Jam() {}
    void addPlaylist(Playlist playlist)
    {
        this->playlists.push_back(playlist);
    }
    void removePlaylist(Playlist playlist)
    {
        this->playlists.remove(playlist);
    }
    void showPlaylists()
    {
        for (auto &playlist : this->playlists)
        {
            cout << "Playlist: " << playlist.getName() << endl;
            playlist.showSongs();
        }
    }
    bool isEmpty()
    {
        return this->playlists.empty();
    }
};

int main()
{
    Playlist playlist1("Rap Español");
    Playlist playlist2("Pop");
    Jam jam;
    int option;
    string song;
    while (true)
    {
        cout << "1. Agregar canción" << endl;
        cout << "2. Eliminar canción" << endl;
        cout << "3. Mostrar playlists" << endl;
        cout << "4. Salir" << endl;
        cout << "Opción: ";
        cin >> option;
        cin.ignore();  // Ignora el '\n' que queda en el buffer después de cin >> option
        switch (option)
        {
        case 1:
            cout << "Canción: ";
            getline(cin, song);
            playlist1.addSong(song);
            break;
        case 2:
            cout << "Canción: ";
            getline(cin, song);
            playlist1.removeSong(song);
            break;
        case 3:
            if (jam.isEmpty())
            {
                cout << "No hay playlists" << endl;
            }
            else
            {
                jam.addPlaylist(playlist1);
                jam.addPlaylist(playlist2);
                jam.showPlaylists();
            }
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}