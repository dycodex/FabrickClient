#include "FabrickUtil.h"

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
