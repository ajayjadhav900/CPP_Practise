#include "calculator.h"

// Implementation of the Calculator class methods
Calculator::Calculator(Dependency* dep) : dependency_(dep) {}

int Calculator::addWithValueFromDependency(int a) {
  return a + dependency_->getValue();
}

bool Calculator::processDataAndGetValue() {
  if (dependency_->process(10)) {
    return dependency_->getValue() > 5;
  }
  return false;
}