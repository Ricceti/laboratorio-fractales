#include "../turtlec.h"

void fractalTree(Turtle *t, float length, float depth){
  if(depth == 0 || length < 5) return;
  if (depth == 4)
    turtleSetColor(t, 80, 40, 10);
  else if (depth == 3)
    turtleSetColor(t, 120, 70, 20);
  else if (depth == 2)
    turtleSetColor(t, 139, 90, 43);
  else
    turtleSetColor(t, 0, 200, 0);

  turtleForward(t, length);

  //rama izquierda
  turtleLeft(t, 30);
  fractalTree(t, length * 0.8, depth - 1);
  //rama central
  turtleRight(t, 30);
  fractalTree(t, length * 0.7, depth - 1);
  //rama derecha
  turtleRight(t, 30);
  fractalTree(t, length * 0.5, depth - 1);
  if (depth == 4)
    turtleSetColor(t, 80, 40, 10);
  else if (depth == 3)
    turtleSetColor(t, 120, 70, 20);
  else if (depth == 2)
    turtleSetColor(t, 139, 90, 43);
  else
    turtleSetColor(t, 0, 200, 0);
  //volver
  turtleLeft(t, 30);
  turtleBackward(t, length);

}

int main(void){
  TurtleApp *app = turtleAppCreate(400, 400, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 200.0f, 400.0f);
  turtlePenDown(t);
  turtleSetSpeed(t, 15);
  turtleLeft(t, 90);

  fractalTree(t, 70, 4);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
