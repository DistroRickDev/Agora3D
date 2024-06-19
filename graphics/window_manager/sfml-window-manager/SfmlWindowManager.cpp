// Copyright (c) 2024. DistroRickDev All Rights Reserved

#include "SfmlWindowManager.h"

bool game_engine::window_manager::SfmlWindowManager::create_window(std::shared_ptr<WindowSettings> const &settings) {
    if(!settings)
    {
        // TODO(): Log error here
        return false;
    }
    if (!_window) {
        _window = std::make_shared<sf::RenderWindow>(
                sf::VideoMode({settings->width, settings->height}),
                settings->title);
    }
    return _window != nullptr;
}

std::shared_ptr<sf::RenderWindow> game_engine::window_manager::SfmlWindowManager::get_window() const {
    return _window;
}
