#ifndef CUBE_H
#define CUBE_H

#include <irr/irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Cube
{
    public:
        Cube(scene::ISceneManager *sceneManager, video::IVideoDriver *videoDriver, const io::path &filename);
        inline void setPosition(const core::vector3df &newpos);
        virtual ~Cube();
    protected:
        ISceneNode* cubeBody;
        scene::ISceneManager *manager;
        video::IVideoDriver *video;
    private:
};

#endif // CUBE_H
