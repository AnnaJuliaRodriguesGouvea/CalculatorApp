#ifndef CALCULATOR_H
#define CALCULATOR_H

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

private:
    Calculator() = default;
};

#endif // CALCULATOR_H
