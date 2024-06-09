#include "calculator.h"

double Calculator::add(double a, double b) {
    if (!std::isfinite(a) || !std::isfinite(b)) {
        throw std::invalid_argument("Input values ​​are not valid.");
    }

    double result = a + b;
    updateCalculations(a, b, result, Addition);
    return result;
}

double Calculator::subtract(double a, double b) {
    if (!std::isfinite(a) || !std::isfinite(b)) {
        throw std::invalid_argument("Input values ​​are not valid.");
    }

    double result = a - b;
    updateCalculations(a, b, result, Subtraction);
    return result;
}

double Calculator::multiply(double a, double b) {
    if (!std::isfinite(a) || !std::isfinite(b)) {
        throw std::invalid_argument("Input values ​​are not valid.");
    }

    double result = a * b;
    updateCalculations(a, b, result, Multiplication);
    return result;
}

double Calculator::divide(double a, double b) {
    if (!std::isfinite(a) || !std::isfinite(b)) {
       throw std::invalid_argument("Input values ​​are not valid.");
    }

    if (b == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    double result = a / b;
    updateCalculations(a, b, result, Division);
    return result;
}

void Calculator::updateCalculations(double value1, double value2, double result, OperationType op) {
    calculations.append(Calculation(value1, value2, result, op));
}
