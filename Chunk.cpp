#include "Chunk.h"
#include "Cube.h"

Chunk::Chunk(scene::ISceneManager *sceneManager,
             video::IVideoDriver *videoDriver,
             const io::path &chunkInfoFile,
             int x,
             int y)
{
    manager = sceneManager;
    video = videoDriver;
    worldPosX = x;
    worldPosY = y;
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<64; j++)
        {
            cubeList.push_back(new Cube(manager, video, "media/t351sml.jpg"));
            cubeList.back()->setPosition(core::vector3df(worldPosX*640+i*10,0,worldPosY*640+j*10));
        }
    }
}

Chunk::~Chunk()
{
    cubeList.clear();
}
