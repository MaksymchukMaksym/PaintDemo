#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <cocos/ui/UIButton.h>

USING_NS_CC;


int chooseoperation=0;
int choosecolor=0;
Label* FontLabel;
std::vector<DrawNode*> paints;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{

    if ( !Scene::init() )
    {
        return false;
    }


    myBrush = DrawNode::create();
    myCircle=DrawNode::create();
    myRect= DrawNode::create();


    
    auto bg = cocos2d::LayerColor::create(Color4B::WHITE);
    this->addChild(bg);

   
    bgToolBarDinam = Sprite::create("bgToolBar.png");
    bgToolBarDinam->setPosition(Vec2(5, 600));
    this->addChild(bgToolBarDinam);

    auto FontBack = Sprite::create("barforFont.png");
    FontBack->setPosition(150,590);
    this->addChild(FontBack);

    FontLabel = Label::create(std::to_string(dotHeight), "Font.ttf", 15);
    FontLabel->setPosition(150, 590);
    FontLabel->setColor(Color3B::BLACK);
    this->addChild(FontLabel);
   //кнопка brush
    auto BrushButton = ui::Button::create("Pain.png", "PainPressed.png");
    BrushButton->setAnchorPoint(Vec2(0, 0));
    BrushButton->setScale(1.7);
    BrushButton->setPosition(Vec2(20, 570));
    BrushButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            chooseoperation = 1;
            break;
        }
        });
    this->addChild(BrushButton);

    //кнопка circle 
  auto  CircleButton = ui::Button::create("circle.png", "circlePressed.png");
    CircleButton->setAnchorPoint(Vec2(0, 0));
    CircleButton->setScale(1.7);
    CircleButton->setPosition(Vec2(210, 570));
    CircleButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            chooseoperation = 2;
            break;
        }
        });
    this->addChild(CircleButton);
    //кнопка rectangle
    auto  RectangleButton = ui::Button::create("Rectangle.png", "RectanglePressed.png");
    RectangleButton->setAnchorPoint(Vec2(0, 0));
    RectangleButton->setScale(1.7);
    RectangleButton->setPosition(Vec2(210, 610));
    RectangleButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            chooseoperation = 4;
            break;
        }
        });
    this->addChild(RectangleButton);
    //кнопка triagle

    
   // кнопка erasor(гумка)
  auto  ErasorButton = ui::Button::create("erasor.png", "erasorPressed.png");
    ErasorButton->setAnchorPoint(Vec2(0, 0));
    ErasorButton->setScale(1.7);
    ErasorButton->setPosition(Vec2(130, 605));
    ErasorButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            chooseoperation = 3;
            break;
        }
        });
    this->addChild(ErasorButton);

    //палітра кольорів(in)
    
  auto WhiteButton = ui::Button::create("White.png", "ColorsPressed.png");
    WhiteButton->setAnchorPoint(Vec2(0, 0));
    WhiteButton->setScale(1.7);
    WhiteButton->setPosition(Vec2(320, 605));
    WhiteButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 1;
            break;
        }
        });
    this->addChild(WhiteButton);

    auto YellowButton = ui::Button::create("Yellow.png", "ColorsPressed.png");
    YellowButton->setAnchorPoint(Vec2(0, 0));
    YellowButton->setScale(1.7);
    YellowButton->setPosition(Vec2(370, 605));
    YellowButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 2;
            break;
        }
        });
    this->addChild(YellowButton);

    auto RedButton = ui::Button::create("Red.png", "ColorsPressed.png");
    RedButton->setAnchorPoint(Vec2(0, 0));
    RedButton->setScale(1.7);
    RedButton->setPosition(Vec2(420, 605));
    RedButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 3;
            break;
        }
        });
    this->addChild(RedButton);

    auto OrangeButton = ui::Button::create("Orange.png", "ColorsPressed.png");
    OrangeButton->setAnchorPoint(Vec2(0, 0));
    OrangeButton->setScale(1.7);
    OrangeButton->setPosition(Vec2(470, 605));
    OrangeButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 4;
            break;
        }
        });
    this->addChild(OrangeButton);

    auto MagentaButton = ui::Button::create("Magenta.png", "ColorsPressed.png");
    MagentaButton->setAnchorPoint(Vec2(0, 0));
    MagentaButton->setScale(1.7);
    MagentaButton->setPosition(Vec2(320, 560));
    MagentaButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 5;
            break;
        }
        });
    this->addChild(MagentaButton);

    auto GreeanButton = ui::Button::create("Green.png", "ColorsPressed.png");
    GreeanButton->setAnchorPoint(Vec2(0, 0));
    GreeanButton->setScale(1.7);
    GreeanButton->setPosition(Vec2(370, 560));
    GreeanButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 6;
            break;
        }
        });
    this->addChild(GreeanButton);

    auto GrayButton = ui::Button::create("Gray.png", "ColorsPressed.png");
    GrayButton->setAnchorPoint(Vec2(0, 0));
    GrayButton->setScale(1.7);
    GrayButton->setPosition(Vec2(420, 560));
    GrayButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 7;
            break;
        }
        });
    this->addChild(GrayButton);

    auto BlueButton = ui::Button::create("Blue.png", "ColorsPressed.png");
    BlueButton->setAnchorPoint(Vec2(0, 0));
    BlueButton->setScale(1.7);
    BlueButton->setPosition(Vec2(470, 560));
    BlueButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 8;
            break;
        }
        });
    this->addChild(BlueButton);


    auto BlackButton = ui::Button::create("Black.png", "ColorsPressed.png");
    BlackButton->setAnchorPoint(Vec2(0, 0));
    BlackButton->setScale(1.7);
    BlackButton->setPosition(Vec2(520, 560));
    BlackButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            choosecolor = 9;
            break;
        }
        });
    this->addChild(BlackButton);

    //палітра кольорів(out)

    auto _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = CC_CALLBACK_1(HelloWorld::onMouseMove, this);
    _mouseListener->onMouseUp = CC_CALLBACK_1(HelloWorld::onMouseUp, this);
    _mouseListener->onMouseDown = CC_CALLBACK_1(HelloWorld::onMouseDown, this);
    _mouseListener->onMouseScroll = CC_CALLBACK_1(HelloWorld::onMouseScroll, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    this->addChild(myBrush);
    this->addChild(myCircle);
    this->addChild(myRect);
    
    myBrush->setLocalZOrder(1);
    myCircle->setLocalZOrder(1);
    BrushButton->setLocalZOrder(3);
    bgToolBarDinam->setLocalZOrder(2);
    CircleButton->setLocalZOrder(3);
    FontBack->setLocalZOrder(3);
    FontLabel->setLocalZOrder(3);
    ErasorButton->setLocalZOrder(3);
    WhiteButton ->setLocalZOrder(3);
    YellowButton->setLocalZOrder(3);
    RedButton->setLocalZOrder(3);
    OrangeButton->setLocalZOrder(3);
    MagentaButton->setLocalZOrder(3);
    GreeanButton->setLocalZOrder(3);
    GrayButton->setLocalZOrder(3);
    BlueButton->setLocalZOrder(3);
    BlackButton->setLocalZOrder(3);
    RectangleButton->setLocalZOrder(3);

    return true;
}

void HelloWorld::onMouseDown(cocos2d::EventMouse* event)
{
    lkm = true;
    Start = event->getLocationInView();
   
   // створення  нової лінії
    if (chooseoperation == 1) {
        myBrush = DrawNode::create();
        this->addChild(myBrush);
        paints.push_back(myBrush);
    }
    //створення нового кола 
    if (chooseoperation == 2) {
        centre = event->getLocationInView();
        myCircle = DrawNode::create();
        this->addChild(myCircle);
        paints.push_back(myCircle);
    }
    // створення  нового квадрата
    if (chooseoperation == 4) {
        side = event->getLocationInView();
        myRect = DrawNode::create();
        this->addChild(myRect);
        paints.push_back(myRect);
    }
    
}

void HelloWorld::onMouseUp(EventMouse* event)
{
    lkm = false;
   
}

void HelloWorld::onMouseMove(EventMouse* event)
{
    //малювання кругу
    if (chooseoperation == 2) {
       // IconErasor->setVisible(false);
      if (lkm) {
        myCircle->clear();
        radius=abs(centre.x - event->getLocationInView().x);   
        switch(choosecolor)
        {
        case 1:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::WHITE);
            break;
        case 2:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::YELLOW);
            break;
        case 3:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::RED);
            break;
        case 4:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::ORANGE);
            break;
        case 5:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::MAGENTA);
            break;
        case 6:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::GREEN);
            break;
        case 7:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::GRAY);
            break;
        case 8:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::BLUE);
            break;
        case 9:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::BLACK);
            break;
        default:  myCircle->drawCircle(centre, radius, dotHeight, 50, false, Color4F::BLACK);
            break;
        
        }
       
       } 
      paints.push_back(myCircle);
    }
  
    //малювання лінії
    if (chooseoperation == 1) {
       // IconErasor->setVisible(false);
        Start = event->getLocationInView();
        if (lkm) {
            switch (choosecolor)
            {
            case 1: myBrush->drawDot(Start, dotHeight, Color4F::WHITE);
                break;
            case 2: myBrush->drawDot(Start, dotHeight, Color4F::YELLOW);
                break;
            case 3: myBrush->drawDot(Start, dotHeight, Color4F::RED);
                break;
            case 4: myBrush->drawDot(Start, dotHeight, Color4F::ORANGE);
                break;
            case 5: myBrush->drawDot(Start, dotHeight, Color4F::MAGENTA);
                break;
            case 6: myBrush->drawDot(Start, dotHeight, Color4F::GREEN);
                break;
            case 7: myBrush->drawDot(Start, dotHeight, Color4F::GRAY);
                break;
            case 8: myBrush->drawDot(Start, dotHeight, Color4F::BLUE);
                break;
            case 9: myBrush->drawDot(Start, dotHeight, Color4F::BLACK);
                break;
            default: myBrush->drawDot(Start, dotHeight, Color4F::BLACK);
                break;

            }
        }
        paints.push_back(myBrush);
    }
    //стирка
    if (chooseoperation == 3) {
        for (auto element : paints) {
            element->clear();
        }
    }
    if (chooseoperation == 4) {
        side2 = event->getLocationInView();
        if (lkm) {
            myRect->clear();
            switch (choosecolor)
            {
            case 1: myRect->drawRect(side, side2, Color4F::WHITE);
                break;
            case 2: myRect->drawRect(side, side2, Color4F::YELLOW);
                break;
            case 3: myRect->drawRect(side, side2, Color4F::RED);
                break;
            case 4: myRect->drawRect(side, side2, Color4F::ORANGE);
                break;
            case 5:  myRect->drawRect(side, side2, Color4F::MAGENTA);
                break;
            case 6:  myRect->drawRect(side, side2, Color4F::GREEN);
                break;
            case 7:  myRect->drawRect(side, side2, Color4F::GRAY);
                break;
            case 8:  myRect->drawRect(side, side2, Color4F::BLUE);
                break;
            case 9:  myRect->drawRect(side, side2, Color4F::BLACK);
                break;
            default:  myRect->drawRect(side, side2, Color4F::BLACK);
                break;

            }

        }
        paints.push_back(myRect);
    }
    
}
void HelloWorld::onMouseScroll(EventMouse* event){

    if (chooseoperation == 1|| chooseoperation == 3) {
    
        if (lkm) {
            dotHeight -= event->getScrollY() * 4;
            if (dotHeight <= 0) {
                dotHeight = 1;
            }
            else if (dotHeight >= 50) {
                dotHeight = 50;
            }
            FontLabel->setString(std::to_string(dotHeight));
         }
    }

}

