#include "gold.h"

Gold::Gold(float x, float y)
{
    position_.x = x;
    position_.y = y;
}

void Gold::setSprite(const sf:: Sprite& sprite)
{
    sprite_ = std::move(sprite);
}

void Gold::setPosition(int x, int y)
{
    position_.x = static_cast<float>(x);
    position_.y = static_cast<float>(y);
}

sf::Sprite Gold::getSprite()
{
    return sprite_;
}

sf::Vector2f Gold::getPosition()
{
    return position_;
}

sf::FloatRect Gold::getBounds()
{
    return sprite_.getGlobalBounds();
}

void Gold::draw(sf::RenderWindow& window)
{
    sprite_.setPosition(position_);
    window.draw(sprite_);
}