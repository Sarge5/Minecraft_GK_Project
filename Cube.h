#ifndef CUBE_H
#define CUBE_H

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/** Klasa Cube
 *      Klasa sluzaca do przechowywania informacji o pojedynczej kostce w grze.
 *      Skladniki klasy:
 *          ISceneNode* cubeBody - obiekt kostki, na nim modyfikujemy wspolrzedne, tekstury, itp.
            scene::ISceneManager *manager - wskaznik na menadzer sceny, nim dodajemy kostke do swiata
            video::IVideoDriver *video - wskaznik na sterownik video, nim pobieramy nowe tekstury, itp.
        Metody klasy:
            Cube(scene::ISceneManager *sceneManager, video::IVideoDriver *videoDriver, const io::path &filename)
                Konstruktor klasy, przekazujemy w nim wskazniki do menedzera sceny i sterownikow oraz sciezke do pliku
                z tekstura dla kostki.
            inline void setPosition(const core::vector3df &newpos)
                Funkcja inline sluzaca do zmiany polozenia kostki, przekazujemy do niej wektor 3 floatow ze
                wspolrzednymi polozenia.
            virtual ~Cube()
                Destruktor klasy, niszczy obiekt kostki na scenie.
 *
 */

class Cube
{
    public:
        Cube(scene::ISceneManager *sceneManager, video::IVideoDriver *videoDriver, const io::path &filename);
        void setPosition(const core::vector3df &newpos);
        virtual ~Cube();
    protected:
        ISceneNode* cubeBody;
        scene::ISceneManager *manager;
        video::IVideoDriver *video;
    private:
};

#endif // CUBE_H
