#ifndef FTXUI_COMPONENT_CONTAINER_HPP
#define FTXUI_COMPONENT_CONTAINER_HPP

#include "ftxui/component/component.hpp"

namespace ftxui {

// A component where focus and events are automatically handled for you.
// List of container:
//
// Please use HorizontalContainer or VerticalContainer.
class Container : public Component {
 public:
  static Container Vertical();
  static Container Horizontal();
  static Container Tab(int* selector);

  ~Container() override = default;

  // Component override.
  bool OnEvent(Event event) override;
  Element Render() override;
  Component* ActiveChild() override;

 protected:
  // Handlers
  using EventHandler = bool (Container::*)(Event);
  bool VerticalEvent(Event event);
  bool HorizontalEvent(Event event);
  bool TabEvent(Event) { return false; }
  EventHandler event_handler_;

  using RenderHandler = Element (Container::*)();
  Element VerticalRender();
  Element HorizontalRender();
  Element TabRender();
  RenderHandler render_handler_;

  int selected_ = 0;
  int* selector_ = nullptr;
};

}  // namespace ftxui

#endif /* end of include guard: FTXUI_COMPONENT_CONTAINER_HPP */
