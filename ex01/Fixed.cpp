#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : fp_value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->fp_value_ = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fp_value_;
}

void Fixed::setRawBits(int const raw) { fp_value_ = raw; }
