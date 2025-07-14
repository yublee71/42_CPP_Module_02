#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const int nb_int);
  Fixed(const float nb_fp);
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int fp_value_;
  static const int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
