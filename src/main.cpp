#include <functional>
#include <iostream>

#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

int main()//int argc, const char **argv)
{
  //std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    //{ std::next(argv), std::next(argv, argc) },
    //true,// show help if requested
    //"Naval Fate 2.0");// version string

  //for (auto const &arg : args) {
    //std::cout << arg.first << arg.second << std::endl;
  //}

  //Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Starting ImGui + SFML");

  sf::RenderWindow window(sf::VideoMode(1024, 1024), "ImGui + SFML = <3");
  window.setFramerateLimit(60);
  ImGui::SFML::Init(window);
  
  constexpr auto scale_factor = 2;
  ImGui::GetStyle().ScaleAllSizes(scale_factor);
  ImGui::GetIO().FontGlobalScale = scale_factor;

  sf::CircleShape shape(400.f);
  shape.setFillColor(sf::Color::Green);
  sf::RectangleShape rectangleShape(sf::Vector2(50.f, 50.f));;

  sf::VertexArray line(sf::LineStrip, 2);
  line[0].color = sf::Color::Blue;
  line[1].color = sf::Color::Blue;
  line[0].position = sf::Vector2(10.f, 0.f);
  line[1].position = sf::Vector2(300.f, 300.f);

  sf::Clock deltaClock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    window.clear();
    window.draw(shape);
    window.draw(rectangleShape);
    window.draw(line);

    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}
