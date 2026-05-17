#ifndef FELIX_THE_CAT_8A_COLORS_H
#define FELIX_THE_CAT_8A_COLORS_H

#include <Arduino.h>

namespace FelixTheCatLED {
  struct RGB_COLOR {
    static const uint8_t BLACK[3];
    static const uint8_t WHITE[3];
    static const uint8_t RED[3];
    static const uint8_t VERMILION[3];
    static const uint8_t ORANGE[3];
    static const uint8_t AMBER[3];
    static const uint8_t YELLOW[3];
    static const uint8_t LIME[3];
    static const uint8_t CHARTREUSE[3];
    static const uint8_t HARLEQUIN[3];
    static const uint8_t GREEN[3];
    static const uint8_t MINT[3];
    static const uint8_t SPRING_GREEN[3];
    static const uint8_t TURQUOISE[3];
    static const uint8_t CYAN[3];
    static const uint8_t SKY_BLUE[3];
    static const uint8_t AZURE[3];
    static const uint8_t CERULEAN[3];
    static const uint8_t BLUE[3];
    static const uint8_t INDIGO[3];
    static const uint8_t VIOLET[3];
    static const uint8_t PURPLE[3];
    static const uint8_t MAGENTA[3];
    static const uint8_t HOT_PINK[3];
    static const uint8_t ROSE[3];
    static const uint8_t CRIMSON[3];
  };

  struct HEX_COLOR {
    static const uint32_t BLACK;
    static const uint32_t WHITE;
    static const uint32_t RED;
    static const uint32_t VERMILION;
    static const uint32_t ORANGE;
    static const uint32_t AMBER;
    static const uint32_t YELLOW;
    static const uint32_t LIME;
    static const uint32_t CHARTREUSE;
    static const uint32_t HARLEQUIN;
    static const uint32_t GREEN;
    static const uint32_t MINT;
    static const uint32_t SPRING_GREEN;
    static const uint32_t TURQUOISE;
    static const uint32_t CYAN;
    static const uint32_t SKY_BLUE;
    static const uint32_t AZURE;
    static const uint32_t CERULEAN;
    static const uint32_t BLUE;
    static const uint32_t INDIGO;
    static const uint32_t VIOLET;
    static const uint32_t PURPLE;
    static const uint32_t MAGENTA;
    static const uint32_t HOT_PINK;
    static const uint32_t ROSE;
    static const uint32_t CRIMSON;
  };
}

#endif // FELIX_THE_CAT_8A_COLORS_H
