#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : fp_value_(0) {}

Fixed::Fixed(const int nb_int) : fp_value_(nb_int << fractional_bits_) {}

Fixed::Fixed(const float nb_fp)
    : fp_value_(roundf(nb_fp * (1 << fractional_bits_))) {}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
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

bool Fixed::operator>(const Fixed &other) const {
  return (fp_value_ > other.fp_value_);
}

bool Fixed::operator<(const Fixed &other) const {
  return (fp_value_ < other.fp_value_);
}

bool Fixed::operator>=(const Fixed &other) const {
  return (fp_value_ >= other.fp_value_);
}

bool Fixed::operator<=(const Fixed &other) const {
  return (fp_value_ <= other.fp_value_);
}

bool Fixed::operator==(const Fixed &other) const {
  return (fp_value_ == other.fp_value_);
}

bool Fixed::operator!=(const Fixed &other) const {
  return (fp_value_ != other.fp_value_);
}

Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) {
  fp_value_++;
  return *this;
}

Fixed &Fixed::operator--(void) {
  fp_value_--;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed fixed(*this);
  fp_value_++;
  return fixed;
}

Fixed Fixed::operator--(int) {
  Fixed fixed(*this);
  fp_value_--;
  return fixed;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) { return (f1 < f2 ? f1 : f2); }

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) { return (f1 > f2 ? f1 : f2); }

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return (f1 > f2 ? f1 : f2);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
