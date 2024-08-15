#include <SFML/Graphics.hpp>

class Gold
{
public:
    Gold() = delete;
    Gold(float x, float y) = delete;
    Gold(const Gold&) = delete;
    Gold(Gold&&) = default;
    Gold& operator=(const Gold&) = delete;
    Gold& operator=(Gold&&) = default;
    ~Gold() = default;

    void setSprite(const sf::Sprite&);
    void setPosition(int x, int y);

    sf::Sprite getSprite();
    sf::Vector2f getPosition();
    sf::FloatRect getBounds();

    void draw(sf::RenderWindow&);
private:
    sf::Vector2f position_;
    sf::Sprite sprite_;
};