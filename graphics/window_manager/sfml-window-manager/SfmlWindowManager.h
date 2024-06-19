// Copyright (c) 2024. DistroRickDev All Rights Reserved

#if !defined(GAME_ENGINE_SFMLWINDOWMANAGER_H)
#define GAME_ENGINE_SFMLWINDOWMANAGER_H

#include "WindowManager.h"

#include <SFML/Graphics.hpp>

#include <memory>

namespace game_engine::window_manager{
struct SfmlWindowManager : public WindowManager<sf::RenderWindow> {
        bool create_window(std::shared_ptr<WindowSettings> const& settings) override;
        std::shared_ptr<sf::RenderWindow> get_window() const override;
    private:
        std::shared_ptr<sf::RenderWindow> _window{};
    };
}



#endif //GAME_ENGINE_SFMLWINDOWMANAGER_H
