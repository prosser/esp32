#include "Page.hh"
#include "App.hh"

Page::Page(App *app, TFT_eSPI *screen, const char *name, PageType type)
{
  this->app = app;
  this->screen = screen;
  this->name = name;
  this->type = type;
}

Page::~Page() {}

void Page::onNavigate()
{
  screen->fillScreen(app->theme->bgColor->color());
}

void Page::render()
{
}

void Page::onBottomButton(ButtonState state)
{
  Serial.printf("Page::onBottomButton(%d)\n", state);
}

void Page::onTopButton(ButtonState state)
{
  Serial.printf("Page::onTopButton(%d)\n", state);
}