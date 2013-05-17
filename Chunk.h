#ifndef CHUNK_H_INCLUDED
#define CHUNK_H_INCLUDED

#include <irrlicht.h>
#include <vector>
#include "Cube.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;


/** Klasa Chunk
        Klasa sluzaca do przechowywania informacji o kostkach znajdujacych sie w otoczeniu gracza. Obszar gry zlozony jest
        z kostek (klasa Cube), kostki te znajduja sie w tablicach wielowymiarowych, ktore sa zarzadzane przez klase Chunk.
        Jeden chunk zawiera informacje o kostkach na obszarze 64x64x256 kostek.
        Skladniki klasy:
            vector<Cube *> cubeList - lista kostek w chunku
            scene::ISceneManager *manager - wskaznik na menadzer sceny
            video::IVideoDriver *video - wskaznik na sterownik video
            int worldPosX - pozycja chunku X w swiecie
            int worldPosY - pozycja chunku Y w swiecie
        Metody klasy:
            Chunk(scene::ISceneManager *sceneManager, video::IVideoDriver *videoDriver, const io::path &chunkInfoFile, int x, int y)
                Konstruktor chunka, w nim generowany jest teren danego chunka, badz odczytywany z pliku.
            virtual ~Chunk()
                Destruktor chunka, niszczy tablice kostek.
 *
 */

class Chunk
{
public:
    Chunk(scene::ISceneManager *sceneManager,
          video::IVideoDriver *videoDriver,
          const io::path &chunkInfoFile,
          int x,
          int y);
    virtual ~Chunk();
protected:
    vector<Cube *> cubeList;
    scene::ISceneManager *manager;
    video::IVideoDriver *video;
    int worldPosX;
    int worldPosY;
private:
};


#endif // CHUNK_H_INCLUDED
