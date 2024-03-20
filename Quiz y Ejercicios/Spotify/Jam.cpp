#include <iostream>
#include <string>

using namespace std;

class Song
{
private:
    string name;
    string artist;
    int duration; // in seconds
public:
    Song() : name(""), artist(""), duration(0) {}
    Song(string name, string artist, int duration) : name(name), artist(artist), duration(duration) {}

    string getName() const
    {
        return this->name;
    }

    void setName(const string &name)
    {
        this->name = name;
    }
    string getArtist() const
    {
        return this->artist;
    }
    void setArtist(const string &artist)
    {
        this->artist = artist;
    }
    int getDuration() const
    {
        return this->duration;
    }
    void setDuration(int duration)
    {
        this->duration = duration;
    }

    string toString()
    {
        return "Nombre: " + name + ", Artista: " + artist + ", Duración: " + to_string(duration) + " segundos";
    }

    bool operator==(const Song &other) const
    {
        return this->name == other.getName() && this->artist == other.getArtist() && this->duration == other.getDuration();
    }

    bool operator<(const Song &other) const
    {
        if (this->name != other.name)
            return this->name < other.name;
        if (this->artist != other.artist)
            return this->artist > other.artist;
        if (this->duration != other.duration)
            return (this->duration >= 60 && this->duration <= 180);
        return false;
    }

    bool operator>(const Song &other) const
    {
        return other < *this;
    }
};

class Node
{
private:
    Song data;
    Node *next;

public:
    Node(Song val) : data(val), next(nullptr){};
    ~Node() { delete next; };
    Song getData() { return data; };
    Node *getNext() { return next; };
    void setNext(Node *next) { this->next = next; };
};

class SongList
{
private:
    Node *head;

public:
    SongList() : head(nullptr) {}

    Node *getHead()
    {
        return head;
    }

    void addSong(Song song)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->getData() == song)
            {
                cout << "La canción ya fue agregada." << endl;
                return;
            }
            current = current->getNext();
        }
        Node *newNode = new Node(song);
        newNode->setNext(head);
        head = newNode;
    }

    void showList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->getData().toString() << endl;
            current = current->getNext();
        }
    }

    bool contains(Song song)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->getData() == song)
            {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }

    void sortList(int sortType)
    {
        if (head == nullptr || head->getNext() == nullptr)
            return;

        Node *sorted = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->getNext();

            if (sorted == nullptr || compareData(sorted->getData(), current->getData(), sortType) > 0)
            {
                current->setNext(sorted);
                sorted = current;
            }
            else
            {
                Node *currentSorted = sorted;
                while (currentSorted->getNext() != nullptr && compareData(currentSorted->getNext()->getData(), current->getData(), sortType) < 0)
                {
                    currentSorted = currentSorted->getNext();
                }
                current->setNext(currentSorted->getNext());
                currentSorted->setNext(current);
            }
            current = next;
        }
        head = sorted;
    }

    int compareData(Song d1, Song d2, int sortType)
    {
        switch (sortType)
        {
        case 1:
            return d1.getArtist().compare(d2.getArtist());
        case 2:
            return d1.getName().compare(d2.getName());
        case 3:
            return d1.getDuration() - d2.getDuration();
        default:
            return 0;
        }
    }

    void searchSongsStartingWith(char letter)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->getData().getName()[0] == letter)
            {
                cout << current->getData().toString() << endl;
            }
            current = current->getNext();
        }
    }

    void searchSongsByArtist(const string &artist)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->getData().getArtist() == artist)
            {
                cout << current->getData().toString() << endl;
            }
            current = current->getNext();
        }
    }

    void searchSongsLongerThan(int duration)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->getData().getDuration() > duration)
            {
                cout << current->getData().toString() << endl;
            }
            current = current->getNext();
        }
    }
};

void addSongsFromDefault(SongList &list, SongList &defaultList)
{
    int index;
    Node *current;
    while (true)
    {
        current = defaultList.getHead();
        index = 0;
        while (current != nullptr)
        {
            cout << index << ": "
                 << "Nombre: " << current->getData().getName()
                 << ", Artista: " << current->getData().getArtist()
                 << ", Duración: " << current->getData().getDuration() << " segundos" << endl;
            current = current->getNext();
            index++;
        }
        cout << "Ingrese el índice de la canción que desea agregar (o -1 para terminar): ";
        cin >> index;
        if (index == -1)
        {
            break;
        }
        current = defaultList.getHead();
        for (int i = 0; i < index && current != nullptr; i++)
        {
            current = current->getNext();
        }
        if (current != nullptr)
        {
            list.addSong(current->getData());
        }
        else
        {
            cout << "Índice inválido." << endl;
        }
    }
}

int main()
{
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
    Node *current = lista1.getHead();
    while (current != nullptr)
    {
        if (lista2.contains(current->getData()))
        {
            listaJam.addSong(current->getData());
        }
        current = current->getNext();
    }

    cout << "Lista Jam sin ordenar: " << endl;
    listaJam.showList();
    cout << endl;
    cout << "Lista Jam ordenada por artista: " << endl;
    listaJam.sortList(1);
    listaJam.showList();
    cout << endl;
    cout << "Lista Jam ordenada por nombre: " << endl;
    listaJam.sortList(2);
    listaJam.showList();
    cout << endl;
    cout << "Lista Jam ordenada por duración: " << endl;
    listaJam.sortList(3);
    listaJam.showList();
    cout << endl;
    cout << "Canciones de la lista Jam que empiezan con la letra 'A': " << endl;
    listaJam.searchSongsStartingWith('A');
    cout << endl;
    cout << "Canciones de la lista Jam del artista 'Reality': " << endl;
    listaJam.searchSongsByArtist("Reality");
    cout << endl;
    cout << "Canciones de la lista Jam con duración mayor a 180 segundos: " << endl;
    listaJam.searchSongsLongerThan(180);
    cout << endl;
    return 0;
}