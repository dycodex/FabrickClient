#include "FabrickUtil.h"

/**
 * Add zeros on the left to pad the string with specified length
 * @param data the string that will be padded with zero
 * @param len maximum length of the resulting string
 * @return zero-padded string
 */
String FabrickUtils::addZeros(String data, int len) {
    int dataLength = data.length();
    String dataii = data;
    if (dataLength < len) {
        for (int ii = 0; ii < len - dataLength; ii++) {
            dataii = "0" + dataii;
        }
    }

    return dataii;
}
