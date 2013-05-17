#include <irr/irrlicht.h>
#include "Cube.h"

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
    camera->setFarValue(1000);

    IAnimatedMesh* mesh = manager->getMesh("media/sydney.md2");
    if (!mesh)
    {
        device->drop();
        return 1;
    }

    Cube *kostka1 = new Cube(manager, video, "media/t351sml.jpg");

    IAnimatedMeshSceneNode* node = manager->addAnimatedMeshSceneNode( mesh );

    if (node)
    {
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setMD2Animation(scene::EMAT_STAND);
        node->setMaterialTexture( 0, video->getTexture("media/sydney.bmp") );
    }
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
    delete kostka1;
    device->drop();
    return 0;
}
