#include "player.h"

Player::Player(float start_x, float start_y, const sf::Sprite& sprite)
{
    player_position_.x = start_x;
    player_position_.y = start_y;
    player_sprite_ = sprite;
}

sf::FloatRect Player::getPosition()
{
    return player_sprite_.getGlobalBounds();
}

int Player::getHealth()
{
    return player_health_;
}

void Player::moveLeft()
{
    player_moving_left_ = true;
}

void Player::moveRight()
{
    player_moving_right_ = true;
}

void Player::stopLeft()
{
    player_moving_left_ = false;
}

void Player::stopRight()
{
    player_moving_right_ = false;
}

void Player::decreaseHealth()
{
    player_health_--;
}

bool Player::ifAlive() const
{
    if(player_health_ > 0)
    {
        return true;
    } else
    {
        return false;
    }
}

void Player::draw(sf::RenderWindow* window) const
{
    window->draw(player_sprite_);
}

void Player::update(const sf::Time& dt)
{
    if(player_moving_left_)
    {
        player_position_.y =+ player_speed_ * dt.asSeconds();
    }
    if(player_moving_right_)
    {
        player_position_.y -= player_speed_ * dt.asSeconds();
    }
    if(player_position_.y > 1280)
    {
        player_position_.y = 1280;
    }
    if(player_position_.y < 0)
    {
        player_position_.y = 0;
    }
    player_sprite_.setPosition(player_position_);
}