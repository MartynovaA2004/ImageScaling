#include <SFML/Graphics.hpp> //для графических фигур

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Picrure");
    
    Texture Picture;
    Picture.loadFromFile("C:/Users/pc/Desktop/Папка Насти/2 курс/4 семестр/АиСД/ImageScaling/output.bmp");
    Sprite Sprite1(Picture);//объект

    while (window.isOpen())	//цикл пока графическое окно не закрыто
    {
        sf::Event event;
        while (window.pollEvent(event))	//проверка событий
        {
            if (event.type == sf::Event::Closed)	//если поступила команда закрытия окна
                window.close();
        };
        window.clear(sf::Color::White);
        window.draw(Sprite1);
        window.display();
    }

}
