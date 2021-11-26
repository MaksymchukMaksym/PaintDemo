#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void onMouseDown(cocos2d::EventMouse* event);
    void onMouseUp(cocos2d::EventMouse* event);
    void onMouseMove(cocos2d::EventMouse* event);
    void onMouseScroll(cocos2d::EventMouse* event);
    cocos2d::DrawNode* myBrush;
    cocos2d::DrawNode* myCircle;
    cocos2d::DrawNode* myRect;

    cocos2d::Vec2 centre;
    cocos2d::Vec2 side;
    cocos2d::Vec2 side2;
    int radius;
    bool lkm = false;
    cocos2d::Vec2 Start;
    int dotHeight = 1;
    float ScrollPos;

   cocos2d::Sprite* bgToolBarDinam;

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
