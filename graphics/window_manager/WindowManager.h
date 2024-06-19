// Copyright (c) 2024. DistroRickDev All Rights Reserved

#if !defined(GAME_ENGINE_WINDOWMANAGER_H)
#define GAME_ENGINE_WINDOWMANAGER_H

#include <cstdint>
#include <memory>
#include <string>

namespace game_engine::window_manager{
    struct WindowSettings
    {
        std::uint32_t width{};
        std::uint32_t height{};
        std::string title{};
    };

    template<typename Window>
    struct WindowManager {
        virtual bool create_window(std::shared_ptr<WindowSettings> const& settings) = 0;
        virtual std::shared_ptr<Window> get_window() const  = 0;
    };
}


#endif //GAME_ENGINE_WINDOWMANAGER_H
