#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : fp_value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb_int) : fp_value_(nb_int << fractional_bits_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb_fp)
    : fp_value_(roundf(nb_fp * (1 << fractional_bits_))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->fp_value_ = other.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const { return fp_value_; }

void Fixed::setRawBits(int const raw) { fp_value_ = raw; }

float Fixed::toFloat(void) const {
  return (float)fp_value_ / (1 << fractional_bits_);
}

int Fixed::toInt(void) const { return fp_value_ >> fractional_bits_; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
