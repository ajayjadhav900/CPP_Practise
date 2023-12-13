#include <iostream>
#include <vector>
class Fraction
{
public:
    int numerator{0};
    int denominator{1};

    Fraction getFraction();
    Fraction multiply(const Fraction &f1, const Fraction &f2);
    void printFraction(const Fraction &f);
};

Fraction Fraction::getFraction()
{
    Fraction temp{};
    std::cout << "Enter a value for numerator: ";
    std::cin >> temp.numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> temp.denominator;
    std::cout << '\n';

    return temp;
}

Fraction multiply(const Fraction &f1, const Fraction &f2)
{
    Fraction temp;
    return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

void Fraction::printFraction(const Fraction &f)
{
    std::cout << f.numerator << '/' << f.denominator << '\n';
}

int main()
{

    std::vector squ = {1, 4, 9, 16, 25};
    std::vector<int> vec(5);
    for(auto itr:vec)
    {
        std::cout<<itr;
    }
    Fraction f1 = f1.getFraction();
    Fraction f2 = f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.printFraction(multiply(f1, f2));

    return 0;
}