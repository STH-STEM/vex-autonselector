// Seb Jensen
// VEXcode V5 Autonomous Routine Selector for Tower Takeover
// 11/02/2020

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

std::string autonRoutine;
int autonRunning;

using namespace vex;

void drawScreen(std::string screen) {
  if (screen == "menu") {
    autonRoutine = "null";

    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("         Red  Blue   ");
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Prot.    (UP)   (X)");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("Unpr.  (DWN)  (B)");

    Brain.Screen.clearScreen();
    Brain.Screen.setPenWidth(3);
    Brain.Screen.setPenColor(white);

    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(20, 17, 210, 90);
    Brain.Screen.drawRectangle(20, 127, 210, 90);

    Brain.Screen.setFont(propL);
    Brain.Screen.setCursor(2, 3);
    Brain.Screen.print("Protected");
    Brain.Screen.setCursor(6, 3);
    Brain.Screen.print("Unprotected");

    Brain.Screen.setFont(propM);
    Brain.Screen.setCursor(4, 4);
    Brain.Screen.print("Goal Zone (Red)");
    Brain.Screen.setCursor(10, 4);
    Brain.Screen.print("Goal Zone (Red)");

    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(250, 17, 210, 90);
    Brain.Screen.drawRectangle(250, 127, 210, 90);

    Brain.Screen.setFont(propL);
    Brain.Screen.setCursor(2, 19);
    Brain.Screen.print("Protected");
    Brain.Screen.setCursor(6, 19);
    Brain.Screen.print("Unprotected");

    Brain.Screen.setFont(propM);
    Brain.Screen.setCursor(4, 28);
    Brain.Screen.print("Goal Zone (Blue)");
    Brain.Screen.setCursor(10, 28);
    Brain.Screen.print("Goal Zone (Blue)");

    wait(0.3, seconds);

    if (autonRunning == 0) {
      while (1 == 1) {
        if (Brain.Screen.pressing()) {
          if (Brain.Screen.xPosition() <= 240) {
            if (Brain.Screen.yPosition() <= 138) {
              drawScreen("redProtected");
              break;
            } else {
              drawScreen("redUnprotected");
              wait(0.25, seconds);
              break;
            }
          } else {
            if (Brain.Screen.yPosition() <= 138) {
              drawScreen("blueProtected");
              break;
            } else {
              drawScreen("blueUnprotected");
              break;
            }
          }
        }
        else if (Controller1.ButtonUp.pressing()){
          drawScreen("redProtected");
          break;
        }
        else if (Controller1.ButtonDown.pressing()){
          drawScreen("redUnprotected");
          break;
        }
        else if (Controller1.ButtonX.pressing()){
          drawScreen("blueProtected");
          break;
        }
        else if (Controller1.ButtonB.pressing()){
          drawScreen("blueUnprotected");
          break;
        }
        wait(0.025, seconds);
      }
    }
  } else if (screen == "redProtected") {
    autonRoutine = "redProtected";

    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Red - Protected");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("(Left) Go Back");

    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(red);

    Brain.Screen.setCursor(2, 3);
    Brain.Screen.setFont(propXL);
    Brain.Screen.print("Red (Protected)");
    Brain.Screen.setCursor(5, 5);
    Brain.Screen.setFont(propM);
    Brain.Screen.print("Auton Selected");

    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(43, 145, 102, 48);
    Brain.Screen.setCursor(9, 7);
    Brain.Screen.print("Go Back");

    if (autonRunning == 0) {
      while (1 == 1) {
        if (Brain.Screen.pressing()) {
          if (Brain.Screen.yPosition() >= 140) {
            drawScreen("menu");
            break;
          }
        }
        if (Controller1.ButtonLeft.pressing()){
          drawScreen("menu");
            break;
        }
        wait(0.025, seconds);
      }
    }
  } else if (screen == "redUnprotected") {
    autonRoutine = "redUnprotected";

    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Red - Unprotect.");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("(Left) Go Back");

    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(red);

    Brain.Screen.setCursor(2, 3);
    Brain.Screen.setFont(propXL);
    Brain.Screen.print("Red (Unprotected)");
    Brain.Screen.setCursor(5, 5);
    Brain.Screen.setFont(propM);
    Brain.Screen.print("Auton Selected");

    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(43, 145, 102, 48);
    Brain.Screen.setCursor(9, 7);
    Brain.Screen.print("Go Back");

    wait(0.5, seconds);

    if (autonRunning == 0) {
      while (1 == 1) {
        if (Brain.Screen.pressing()) {
          if (Brain.Screen.yPosition() >= 140) {
            drawScreen("menu");
            break;
          }
        }
        if (Controller1.ButtonLeft.pressing()){
          drawScreen("menu");
            break;
        }
        wait(0.025, seconds);
      }
    }
  } else if (screen == "blueProtected") {
    autonRoutine = "blueProtected";

    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Blue - Protected");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("(Left) Go Back");

    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(blue);

    Brain.Screen.setCursor(2, 3);
    Brain.Screen.setFont(propXL);
    Brain.Screen.print("Blue (Protected)");
    Brain.Screen.setCursor(5, 5);
    Brain.Screen.setFont(propM);
    Brain.Screen.print("Auton Selected");

    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(43, 145, 102, 48);
    Brain.Screen.setCursor(9, 7);
    Brain.Screen.print("Go Back");

    wait(0.5, seconds);

    if (autonRunning == 0) {
      while (1 == 1) {
        if (Brain.Screen.pressing()) {
          if (Brain.Screen.yPosition() >= 140) {
            drawScreen("menu");
            break;
          }
        }
        if (Controller1.ButtonLeft.pressing()){
          drawScreen("menu");
            break;
        }
        wait(0.025, seconds);
      }
    }
  } else if (screen == "blueUnprotected") {
    autonRoutine = "blueUnprotected";

    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Blue - Unprotect.");
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("(Left) Go Back");

    Brain.Screen.clearScreen();
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(blue);

    Brain.Screen.setCursor(2, 3);
    Brain.Screen.setFont(propXL);
    Brain.Screen.print("Blue (Unprotected)");
    Brain.Screen.setCursor(5, 5);
    Brain.Screen.setFont(propM);
    Brain.Screen.print("Auton Selected");

    Brain.Screen.setPenColor(white);
    Brain.Screen.drawRectangle(43, 145, 102, 48);
    Brain.Screen.setCursor(9, 7);
    Brain.Screen.print("Go Back");

    wait(0.5, seconds);

    if (autonRunning == 0) {
      while (1 == 1) {
        if (Brain.Screen.pressing()) {
          if (Brain.Screen.yPosition() >= 140) {
            drawScreen("menu");
            break;
          }
        }
        if (Controller1.ButtonLeft.pressing()){
          drawScreen("menu");
            break;
        }
        wait(0.025, seconds);
      }
    }
  } else if (screen == "autonRun") {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(propM);
    Brain.Screen.setCursor(2,3);
    Brain.Screen.print("Autonomous in Progress");
    Brain.Screen.setCursor(3,3);
  } else if (screen == "driverControlRun") {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(propM);
    Brain.Screen.setCursor(2,3);
    Brain.Screen.print("Driver Control in Progress");
  }
}

int main() {
  vexcodeInit();
  drawScreen("menu");
}
