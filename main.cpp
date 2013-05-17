#include <irrlicht.h>
#include "Cube.h"
#include "Chunk.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()

{
    IrrlichtDevice * device = createDevice( EDT_OPENGL, core::dimension2d < u32 >( 1280, 1024),
    32, false, false, false, 0 );

    device->setWindowCaption(L"Hello world!");

    video::IVideoDriver * video = device->getVideoDriver();
    scene::ISceneManager * manager = device->getSceneManager();
    gui::IGUIEnvironment * gui = device->getGUIEnvironment();

    gui->addStaticText(L"Static Text", rect<s32>(10,10,260,22), true, true);
    scene::ICameraSceneNode * camera = manager->addCameraSceneNodeFPS();
    camera->setFarValue(100);

    //Cube *kostka1 = new Cube(manager, video, "media/t351sml.jpg");
    Chunk *chunk1 = new Chunk(manager, video, "media/t351sml.jpg", 0, 0);
    Chunk *chunk2 = new Chunk(manager, video, "media/t351sml.jpg", -1, -1);
    Chunk *chunk3 = new Chunk(manager, video, "media/t351sml.jpg", 0, -1);
    Chunk *chunk4 = new Chunk(manager, video, "media/t351sml.jpg", -1, 0);

    //node->remove();
    int lastFPS = -1;
    while( device->run() )
    {
        video->beginScene( true, true, video::SColor( 255, 0, 10, 200 ) );
        int fps = video->getFPS();
        if (lastFPS != fps)
        {
            core::stringw str = L"FPS: ";
            str += fps;

            device->setWindowCaption(str.c_str());
            lastFPS = fps;
        }
        manager->drawAll();
        gui->drawAll();
        video->endScene();

    }
    //delete kostka1;
    delete chunk1;
    delete chunk2;
    delete chunk3;
    delete chunk4;
    device->drop();
    return 0;
}
