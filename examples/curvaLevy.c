#include <math.h>
#include "../turtlec.h"

void levy(Turtle *t, float length, int depth){
  if(depth == 0){
    turtleForward(t, length);
    return;
  }

  turtleLeft(t, 45);
  levy(t, length / sqrt(2), depth - 1);

  turtleRight(t, 90);
  levy(t, length / sqrt(2), depth - 1);

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
  levy(t, 300, 10);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
