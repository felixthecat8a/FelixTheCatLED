#ifndef FELIX_THE_CAT_8A_COLORS_H
#define FELIX_THE_CAT_8A_COLORS_H

#include <Arduino.h>

namespace FelixTheCatLED {
  struct RGB_Color {
    uint8_t r, g, b;

    constexpr uint32_t hex() const {
      return (uint32_t(r) << 16) | (uint32_t(g) << 8) | b;
    }
  };

  namespace ColorRGB {
    constexpr RGB_Color BLACK        = { 0, 0, 0 };
    constexpr RGB_Color WHITE        = { 255, 255, 255 };
    constexpr RGB_Color RED          = { 255, 0, 0 };
    constexpr RGB_Color VERMILION    = { 255, 64, 0 };
    constexpr RGB_Color ORANGE       = { 255, 128, 0 };
    constexpr RGB_Color AMBER        = { 255, 191, 0 };
    constexpr RGB_Color YELLOW       = { 255, 255, 0 };
    constexpr RGB_Color LIME         = { 191, 255, 0 };
    constexpr RGB_Color CHARTREUSE   = { 128, 255, 0 };
    constexpr RGB_Color HARLEQUIN    = { 64, 255, 0 };
    constexpr RGB_Color GREEN        = { 0, 255, 0 };
    constexpr RGB_Color MINT         = { 0, 255, 64 };
    constexpr RGB_Color SPRING_GREEN = { 0, 255, 128 };
    constexpr RGB_Color TURQUOISE    = { 0, 255, 191 };
    constexpr RGB_Color CYAN         = { 0, 255, 255 };
    constexpr RGB_Color SKY_BLUE     = { 0, 191, 255 };
    constexpr RGB_Color AZURE        = { 0, 128, 255 };
    constexpr RGB_Color SAPPHIRE     = { 0, 64, 255 };
    constexpr RGB_Color BLUE         = { 0, 0, 255 };
    constexpr RGB_Color INDIGO       = { 64, 0, 255 };
    constexpr RGB_Color VIOLET       = { 128, 0, 255 };
    constexpr RGB_Color PURPLE       = { 191, 0, 255 };
    constexpr RGB_Color MAGENTA      = { 255, 0, 255 };
    constexpr RGB_Color HOT_PINK     = { 255, 0, 191 };
    constexpr RGB_Color ROSE         = { 255, 0, 128 };
    constexpr RGB_Color CRIMSON      = { 255, 0, 64 };
  }
}

#endif // FELIX_THE_CAT_8A_COLORS_H
