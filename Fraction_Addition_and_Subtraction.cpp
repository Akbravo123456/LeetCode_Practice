class Solution {
 public:
  string fractionAddition(string expression) {
    istringstream iss(expression);
    char _;
    int a;
    int b;
    int num = 0;
    int den = 1;

    while (iss >> a >> _ >> b) {
      num= num * b + a * den;
      den *= b;
      const int g = abs(__gcd(num, den));
      num /= g;
      den /= g;
    }
    return to_string(num) + "/" + to_string(den);
  }
};