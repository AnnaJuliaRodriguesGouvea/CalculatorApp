#include "calculator.h"
#include <QDebug>
#include <QMessageBox>

double Calculator::handleException(const std::exception& e) {
    qDebug() << "Exception caught: " << e.what();
    QMessageBox::critical(nullptr, "Error", QString::fromStdString(e.what()));
    return std::numeric_limits<double>::quiet_NaN();
}

double Calculator::sum(double a, double b) {
    try {
        if (!std::isfinite(a) || !std::isfinite(b)) {
            throw std::invalid_argument("Input values ​​are not valid.");
        }

        double result = a + b;
        updateCalculations(a, b, result, Sum);
        return result;
    } catch (const std::invalid_argument& e) {
        return handleException(e);
    }

}

double Calculator::subtract(double a, double b) {
    try {
        if (!std::isfinite(a) || !std::isfinite(b)) {
            throw std::invalid_argument("Input values ​​are not valid.");
        }

        double result = a - b;
        updateCalculations(a, b, result, Subtraction);
        return result;
    } catch (const std::invalid_argument& e) {
        return handleException(e);
    }
}

double Calculator::multiply(double a, double b) {
    try {
        if (!std::isfinite(a) || !std::isfinite(b)) {
            throw std::invalid_argument("Input values ​​are not valid.");
        }

        double result = a * b;
        updateCalculations(a, b, result, Multiplication);
        return result;
    } catch (const std::invalid_argument& e) {
        return handleException(e);
    }
}

double Calculator::divide(double a, double b) {
    try {
        if (!std::isfinite(a) || !std::isfinite(b)) {
            throw std::invalid_argument("Input values ​​are not valid.");
        }

        if (b == 0.0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        double result = a / b;
        updateCalculations(a, b, result, Division);
        return result;
    } catch (const std::invalid_argument& e) {
        return handleException(e);
    }
}

void Calculator::updateCalculations(double value1, double value2, double result, OperationType op) {
    calculations.append(Calculation(value1, value2, result, op));
}
