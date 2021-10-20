#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1280, 720), "SFML works!");
    Texture texture;
    texture.loadFromFile("C:\\Users\\Руслан\\Desktop\\oop\\SFML App1\\image\\Boot.png");
    Sprite sprite(texture, IntRect(0, 0, 1200, 1200));
    sprite.scale(0.17,0.17);

    Texture texture1;
    texture1.loadFromFile("C:\\Users\\Руслан\\Desktop\\oop\\SFML App1\\image\\money.png");
    Sprite sprite1(texture1, IntRect(0, 0, 960, 960));
    sprite1.scale(0.2, 0.2);
    //sprite.setTextureRect(IntRect(0, 0, 500, 500));
    sprite1.setPosition(0, 0);//120 77

    Texture background;
    background.loadFromFile("C:\\Users\\Руслан\\Desktop\\background.jpg");
    Sprite fonSprite(background);

    //RectangleShape rectangle;
    //rectangle.setSize(Vector2f(100, 50));
    //rectangle.setPosition(500, 0);
    
    double x = 540, y = 260, z = 0, yh=0, x1=0, speed=1;
    srand(time(NULL));
    Transform transform;
    while (window.isOpen())
    {
        Event event;

        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
            case Event::Closed:
                window.close();
                break;

            /*case Event::KeyReleased:
                if (Keyboard::Space) z += 0.3;
                std::cout << "test";
                break;*/
                    

                // we don't process other types of events
            default:
                break;
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            x -=  speed;
            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            y -= speed;
            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            y += speed;
            std::cout << x << " " << y << std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            x += speed;

            std::cout << x << " " << y<<std::endl;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            
        }



        fonSprite.setPosition(0, 0);
        window.clear();
        window.draw(fonSprite);



        y += 0.5;
        yh += 1.3;
        
        if (yh > 720)
        {
            x1 = rand() % 1150;
            yh = -200;
        }
        if (x)

        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (y > 520) y = 520;
        if (x > 1080)x = 1080;
        sprite.setPosition(x, y);
        sprite1.setPosition(x1, yh);
        //transform.rotate(z, x + 100, y + 100);
        window.clear();
        //window.draw(rectangle/*, transform*/);
        window.draw(sprite);
        window.draw(sprite1);
        window.display();
    }

    return 0;
}