#include "../turtlec.h"
void dibujarReloj(*t){
  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 3.5f);
  for(int i = 0; i < 12; i++){
    turtlePenUp(t);
    turtleGoTo(t, 200.0f, 200.0f);
    turtleForward(t, 80.0f);
    turtlePenDown(t);
    turtleForward(t, 20.0f);
    turtleRight(t, 30.0f);
  }
}

int main(void){
  TurtleApp *app = turtleAppCreate(400, 400, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 200.0f, 200.0f);
  turtlePenDown(t);

  dibujarReloj(t);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
