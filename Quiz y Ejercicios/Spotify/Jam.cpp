#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    string name;
    string artist;
    int duration; // in seconds

    Song(string name, string artist, int duration) : name(name), artist(artist), duration(duration) {}

    bool operator==(const Song& other) const {
        return name == other.name && artist == other.artist && duration == other.duration;
    }
};

class Node {
public:
    Song data;
    Node *next;

    Node (Song val): data(val), next(nullptr) {};
};

class SongList {
public:
    Node* head;

    SongList() : head(nullptr) {}

    void addSong(Song song) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == song) {
                cout << "La canción ya fue agregada." << endl;
                return;
            }
            current = current->next;
        }
        Node *newNode = new Node(song);
        newNode->next = head;
        head = newNode;
    }

    void showList() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Nombre: " << current->data.name << ", Artista: " << current->data.artist << ", Duración: " << current->data.duration << " segundos" << endl;
            current = current->next;
        }
    }

    bool contains(Song song) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == song) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

void addSongsFromDefault(SongList& list, SongList& defaultList) {
    int index;
    Node* current;
    while (true) {
        current = defaultList.head;
        index = 0;
        while (current != nullptr) {
            cout << index << ": " << "Nombre: " << current->data.name << ", Artista: " << current->data.artist << ", Duración: " << current->data.duration << " segundos" << endl;
            current = current->next;
            index++;
        }
        cout << "Ingrese el índice de la canción que desea agregar (o -1 para terminar): ";
        cin >> index;
        if (index == -1) {
            break;
        }
        current = defaultList.head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        if (current != nullptr) {
            list.addSong(current->data);
        } else {
            cout << "Índice inválido." << endl;
        }
    }
}

int main() {
    SongList listaDefault;
    listaDefault.addSong(Song("Aunque Duela", "Reality", 156));
    listaDefault.addSong(Song("Billie Jean", "Michael Jackson", 296));
    listaDefault.addSong(Song("My Lie", "Zolik", 176));
    listaDefault.addSong(Song("Scars", "1nonly", 147));
    listaDefault.addSong(Song("Una Vaina Loca", "Fuego", 189));
    listaDefault.addSong(Song("Another Love", "Tom Odell", 244));
    listaDefault.addSong(Song("Viva la vida", "Coldplay", 242));

    SongList lista1;
    cout << "Seleccione las canciones para la lista 1:" << endl;
    addSongsFromDefault(lista1, listaDefault);

    SongList lista2;
    cout << "Seleccione las canciones para la lista 2:" << endl;
    addSongsFromDefault(lista2, listaDefault);

    SongList listaJam;
    Node* current = lista1.head;
    while (current != nullptr) {
        if (lista2.contains(current->data)) {
            listaJam.addSong(current->data);
        }
        current = current->next;
    }

    cout << "Lista Jam: " << endl;
    listaJam.showList();

    return 0;
}