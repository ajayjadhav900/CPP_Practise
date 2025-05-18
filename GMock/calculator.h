#ifndef CALCULATOR_H
#define CALCULATOR_H

class Dependency {
public:
  virtual ~Dependency() = default;
  virtual int getValue() = 0;
  virtual bool process(int data) = 0;
};

class Calculator {
public:
  Calculator(Dependency* dep);

  int addWithValueFromDependency(int a);
  bool processDataAndGetValue();

private:
  Dependency* dependency_;
};

#endif // CALCULATOR_H