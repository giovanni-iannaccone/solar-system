#ifndef data_hpp
#define data_hpp

#include "star.hpp"

#define STARS_NUM 10

#define SUN_RADIUS  48.74
#define MER_RADIUS  7.32
#define VEN_RADIUS  18.15
#define EAR_RADIUS  19.13
#define MOO_RADIUS  6.15
#define MAR_RADIUS  10.19
#define JUP_RADIUS  42.90
#define SAT_RADIUS  36.16
#define URA_RADIUS  25.56
#define NEP_RADIUS  24.78

#define MER_SUN_DIS 74.47
#define VEN_SUN_DIS 138.67
#define EAR_SUN_DIS 201.60
#define MOO_EAR_DIS 31.21
#define MAR_SUN_DIS 273.60
#define JUP_SUN_DIS 400.08
#define SAT_SUN_DIS 513.72
#define URA_SUN_DIS 1017.60
#define NEP_SUN_DIS 1138.8 

#define MER_SPEED   87.0
#define VEN_SPEED   225.0
#define EAR_SPEED   365.0
#define MOO_SPEED   30.0
#define MAR_SPEED   687.0
#define JUP_SPEED   1298.4
#define SAT_SPEED   3225.6
#define URA_SPEED   3066.4
#define NEP_SPEED   6014.8

#define SELFROTATE  3

#define SET_VALUE_3(name, value0, value1, value2) \
                   ((name)[0])=(value0), ((name)[1])=(value1), ((name)[2])=(value2)

enum STARS {
    Sun,
    Mercury,
    Venus,
    Earth,
    Moon,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune
};

#endif