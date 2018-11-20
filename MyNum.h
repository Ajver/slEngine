#pragma once

#include <string>

class MyNum {
public:

	MyNum() { to_zero(); }
	MyNum(int a) { *this = (a); }
	MyNum(std::string a) { *this = (a); }
	MyNum(MyNum &a) { *this = a; }

	const int MAX_LEN = 30;

	// Value of number
	char val[30]{ 0 };

	bool operator == (MyNum &a) {
		if (_len == a.len()) {
			for (int i = MAX_LEN - 1; i >= MAX_LEN - _len; i--) {
				if (val[i] != a.val[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool operator != (MyNum &a) {
		return !(*this == a);
	}

	void operator -= (MyNum &a) {
		if (*this > a) {
			if (a.positive()) {
				_len = fmax(_len, a.len());
				int b = fmax(MAX_LEN - a.len() - 2, 0);
				for (int i = MAX_LEN - 1; i >= b; i--) {
					char n = val[i] - a.val[i];
					if (n < 0) {
						if (i > 0) {
							val[i - 1]--;
						}
						n += 10;
					}
					val[i] = n;
				}
				while (_len > 1 && val[MAX_LEN - _len] == 0) {
					_len--;
				}
			}
			else {
				MyNum cp = a;
				cp.switch_sign();
				*this += (cp);
			}
		}
	}

	void operator -= (int a) {
		MyNum na = a;
		*this -= (na);
	}

	void operator += (MyNum &a) {
		if (a.positive()) {
			_len = fmax(_len, a.len());
			int b = fmax(MAX_LEN - a.len() - 2, 0);
			char offset = 0;
			for (int i = MAX_LEN - 1; i >= b; i--) {
				char n = val[i] + a.val[i] + offset;
				val[i] = n % 10;
				offset = n / 10;
			}
			if (_len < MAX_LEN) {
				if (val[MAX_LEN - _len - 1] != 0) {
					_len++;
				}
			}
		}
		else {
			MyNum cp = a;
			cp.switch_sign();
			*this -= (cp);
		}
	}

	void operator += (int a) {
		MyNum na = a;
		*this += (na);
	}

	void operator *= (MyNum &a) {
		MyNum n = 0;
		for (MyNum i = 0; i < a; i += 1) {
			n += *this;
		}
		*this = n;
	}

	void operator *= (int a) {
		MyNum na = a;
		*this *= (na);
	}

	void operator /= (MyNum &a) {
		if (!a.is_zero()) {
			MyNum counter = 0;
			while (*this >= (a)) {
				*this -= (a);
				counter += 1;
			}
			*this = counter;
		}
	}

	void operator /= (int a) {
		MyNum na = a;
		*this /= (na);
	}

	MyNum& operator % (MyNum &a) {
		MyNum cp = copy();
		if (!a.is_zero()) {
			while (cp >= a) {
				cp -= a;
			}
		}
		return *(new MyNum(cp));
	}

	MyNum& operator + (MyNum &a) {
		MyNum cp = *this;
		cp += a;
		return *(new MyNum(cp));
	}

	MyNum& operator + (int a) {
		MyNum na = a;
		return *this + na;
	}

	MyNum& operator - (MyNum &a) {
		MyNum cp = *this;
		cp -= a;
		return *(new MyNum(cp));
	}

	MyNum& operator - (int a) {
		MyNum na = a;
		return *this - na;
	}

	void operator = (std::string a) {
		to_zero();
		if (a.length() == 0) {
			return;
		}
		_len = a.length();
		if (a[0] == '-') {
			_positive = false;
			_len--;
		}
		for (int i = 1; i <= _len; i++) {
			val[MAX_LEN - i] = a[a.length() - i] - 48;
		}
	}

	void operator = (MyNum &a) {
		to_zero();
		_len = a.len();
		for (int i = MAX_LEN - 1; i >= MAX_LEN - a.len(); i--) {
			val[i] = a.val[i];
		}
		_positive = a.positive();
	}

	void operator = (int a) {
		*this = (std::to_string(a));
	}

	bool operator < (MyNum &a) {
		if (_positive && !a.positive()) {
			return false;
		}
		if (!_positive && a.positive()) {
			return true;
		}
		if (_len < a.len()) {
			return _positive && a.positive();
		}
		if (_len > a.len()) {
			return !_positive && !a.positive();
		}
		for (int i = MAX_LEN - _len; i < MAX_LEN; i++) {
			if (val[i] < a.val[i]) {
				return _positive && a.positive();
			}
			if (val[i] > a.val[i]) {
				return !_positive && !a.positive();
			}
		}
		return false;
	}

	bool operator >= (MyNum &a) {
		return !(*this < (a));
	}

	bool operator > (MyNum &a) {
		return a < *this;
	}

	bool operator <= (MyNum &a) {
		return !(*this > (a));
	}

	bool is_zero() {
		return _len <= 1 && val[MAX_LEN - 1] == 0;
	}

	void to_zero() {
		for (int i = 0; i < MAX_LEN; i++) {
			val[i] = 0;
		}
		_len = 1;
		_positive = true;
	}

	std::string str() {
		std::string str = "";
		if (!_positive) {
			str += '-';
		}
		for (int i = MAX_LEN - _len; i < MAX_LEN; i++) {
			str += val[i] + 48;
		}
		return str;
	}

	MyNum& copy() {
		return *(new MyNum(*this));
	}

	void switch_sign() { _positive = !_positive; }

	int len() const { return _len; }
	bool positive() const { return _positive; }

private:
	int _len = 1;
	bool _positive = true;
};
