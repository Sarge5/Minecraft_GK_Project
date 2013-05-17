#include "Cube.h"

Cube::Cube(scene::ISceneManager *sceneManager, video::IVideoDriver *videoDriver, const io::path &filename)
{
    manager = sceneManager;
    video = videoDriver;
    cubeBody = manager->addCubeSceneNode();
    cubeBody->setMaterialTexture(0, video->getTexture(filename));
    cubeBody->setMaterialFlag(video::EMF_LIGHTING, false);
}

inline void Cube::setPosition(const core::vector3df &newpos)
{
    cubeBody->setPosition(newpos);
}

Cube::~Cube()
{
    cubeBody->remove();
}
