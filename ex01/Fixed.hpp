#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &other);
  ~Fixed();

  Fixed &operator=(const Fixed &other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int fp_value_;
  static const int fractional_bits_ = 8;
};

#endif
