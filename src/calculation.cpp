#include "calculation.h"

QString Calculation::getOperationString() const {
    switch (operationType) {
    case Sum: return "+";
    case Subtraction: return "-";
    case Multiplication: return "*";
    case Division: return "/";
    default: return "";
    }
}
