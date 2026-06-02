#include <math.h>
#include "../turtlec.h"

void levy(Turtle *t, float length, int depth, int colorIndex){
  if(depth == 0){
    int c = colorIndex % 5;
    if(c == 0)       turtleSetColor(t, 255, 0, 0);
    else if(c == 1)  turtleSetColor(t, 255, 165, 0);
    else if(c == 2)  turtleSetColor(t, 255, 255, 0);
    else if(c == 3)  turtleSetColor(t, 0, 200, 255);
    else             turtleSetColor(t, 180, 0, 255);
    turtleForward(t, length);
    return;
  }

  turtleLeft(t, 45);
  levy(t, length / sqrt(2), depth - 1, colorIndex + 1);

  turtleRight(t, 90);
  levy(t, length / sqrt(2), depth - 1, colorIndex + 2);

  turtleLeft(t, 45);
}

int main(void){
  TurtleApp *app = turtleAppCreate(600, 600, "Curva de Levy C");
  if(app == NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtlePenUp(t);
  turtleGoTo(t, 150.0f, 300.0f);
  turtlePenDown(t);
  turtleSetSpeed(t, 40.0f);
  levy(t, 300, 10, 10);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
