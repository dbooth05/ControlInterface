#include <algorithm>
#include <cstdlib>
#include <iostream>

#include <rclcpp/rclcpp.hpp>

#include <SDL2/SDL.h>
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "custom_elements.hpp"
#include "formatted_elements.hpp"

#include "application.hpp"

using std::make_shared;

int main(int argc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    // Load ROS2
    rclcpp::init(argc, argv);

    auto node = make_shared<Application>();
    rclcpp::spin(node);

    node = nullptr;

    return 0;
}
