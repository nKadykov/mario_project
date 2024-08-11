#pragma once
#include <SFML/Graphics.hpp>

class Player 
{
public:
    Player() = delete;
    Player(float, float, const sf::Sprite&);
    Player(const Player&) = delete;
    Player(Player&&) = delete;
    Player& operator=(const Player&) = delete;
    Player& operator=(Player&&) = delete;
    
    sf::FloatRect getPosition();
    int getHealth();

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void decreaseHealth();
    bool ifAlive() const;
    
    void draw(sf::RenderWindow&) const;
    void update(const sf::Time& dt);
private:
    sf::Vector2f player_position_;
    sf::Texture player_texture_;
    sf::Sprite player_sprite_;
    float player_speed_ = 700.0f;
    bool player_moving_left_ = false;
    bool player_moving_right = false;
    int player_health_ = 4;
    bool is_alive_ = true;
};