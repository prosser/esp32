#include <TFT_eSPI.h> // Hardware-specific library
#include "App.hpp"
#include "pages/Page.hpp"
#include "Log.hpp"

Log *log;
App *app;

unsigned long lastScreenRefresh = 0;                             // in micros
unsigned long lastScreenBlank = 0;                               // in
#define TFT_REFRESH_DELAY 16000                                  // only refresh the screen every 16.7ms
const unsigned long TFT_BLANK_INTERVAL = TFT_REFRESH_DELAY * 60; // blank the screen every second

void app_main()
{
  log = new Log(0);
  log->writeln("Starting...");
  app = new App();

  while (true)
  {
    unsigned long now = micros();
    app->loopStartMicros = now;

    app->readInputs();
    if (lastScreenBlank == now || now - lastScreenRefresh > TFT_REFRESH_DELAY)
    {
      lastScreenRefresh = now;
      app->refresh();
    }

    // sleep for a millisecond to avoid a tight loop (draws too much power)
    delay(1);
  }
}