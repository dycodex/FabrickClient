#ifndef FABRICK_UTILITES_H
#define FABRICK_UTILITES_H

#include <Arduino.h>

/**
 * Utility class for Fabrick client
 */
class FabrickUtils {
public:
    static String addZeros(String data, int len);
};

#endif
