#include <iostream>

class GameEntity {
protected:
    int x, y;

public:
    virtual void move() = 0;

    virtual void getPosition() {
        std::cout << "Current position: (" << x << ", " << y << ")" << std::endl;
    }
};

class Player : public GameEntity {
public:
    void move() override {
        // Implement player movement logic
    }
};

class Enemy : public GameEntity {
public:
    void move() override {
        // Implement enemy movement logic
    }
};

// Usage:
int main() {
    GameEntity* player = new GameEntity();
    player->move();
    player->getPosition();

    delete player;

    return 0;
}
