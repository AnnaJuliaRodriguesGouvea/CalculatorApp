#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QList>
#include "calculation.h"

class Calculator
{
public:
    static Calculator& getInstance() {
        static Calculator instance;
        return instance;
    }

    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

    const QList<Calculation>& getCalculations() const { return calculations; }

private:
    Calculator() = default;
    QList<Calculation> calculations;

    double handleException(const std::exception& e);
    void updateCalculations(double value1, double value2, double result, OperationType op);
};

#endif // CALCULATOR_H
