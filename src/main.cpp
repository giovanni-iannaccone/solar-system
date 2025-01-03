#include <iostream>
#include <GL/glut.h>
#include "../include/solar_system.hpp"

#define HEIGHT  700
#define WIDTH   700
#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50

SolarSystem solarsystem;

inline void onDisplay() {
    solarsystem.onDisplay();
}

inline void onKeyboard(unsigned char key, int x, int y) {
    solarsystem.onKeyboard(key, x, y);
}

inline void onUpdate() {
    solarsystem.onUpdate();
}

inline void showHelp() {
    std::cout   << "Solar System Simulation Controls:" << std::endl
                << "---------------------------------" << std::endl
                << "W - Move camera up (Y-axis)" << std::endl
                << "S - Move camera down (Y-axis)" << std::endl
                << "A - Move camera left (X-axis)" << std::endl
                << "D - Move camera right (X-axis)" << std::endl
                << "Q - Move camera forward (Z-axis)" << std::endl
                << "E - Move camera backward (Z-axis)" << std::endl
                << "Shift + [W/S/A/D/Q/E] - Move faster" << std::endl
                << "R - Reset camera to default position" << std::endl
                << "Esc - Exit the simulation" << std::endl
                << "---------------------------------" << std::endl;
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Solar System Simulation");

    glutDisplayFunc(onDisplay);
    glutIdleFunc(onUpdate);
    glutKeyboardFunc(onKeyboard);

    showHelp();

    glutMainLoop();
    return 0;
}
