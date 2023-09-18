#pragma once
#include "pch.hpp"
#include "map.hpp"
#include "monster.hpp"
#include "controller.hpp"
#include "find_path.hpp"

class GameContext final: public Singlton<GameContext> {
public:
    bool ShouldClose() const { return shouldClose_; }
    void Exit() { shouldClose_ = true; }
    SDL_Event& GetEvent() { return event_; }

    GameContext();

    void HandleEvent() {
        controller->HandleEvent(event_);
    }

    std::unique_ptr<Map> gameMap;
    std::vector<Monster> monsters;
    std::unique_ptr<Controller> controller; 

    void Update();

private:
    bool shouldClose_ = false;
    SDL_Event event_;
    int score_ = 0;

    void dealCollideWithMap(Monster& monster);
    void tryEatBean(const Vector2& playerPosition);
};
