#include <iostream>
#include <string>
#include <vector>

double safe_stod(const std::string &str) {
    if (str.empty()) {
        return 0.0;
    }
    return std::stod(str);
}


int main() {
    std::string complex_str;

    if (std::cin >> complex_str) {
        double real_part = 0.0;
        double imag_part = 0.0;

        size_t pos_i = complex_str.find('i');

        if (pos_i == std::string::npos) {
            real_part = safe_stod(complex_str);
            imag_part = 0.0;
        } else {
            size_t pos_plus = complex_str.rfind('+', pos_i - 1);
            size_t pos_minus = complex_str.rfind('-', pos_i - 1);

            size_t sign_pos = std::string::npos;

            if (pos_plus != std::string::npos && pos_minus != std::string::npos) {
                sign_pos = std::max(pos_plus, pos_minus);
            } else if (pos_plus != std::string::npos) {
                sign_pos = pos_plus;
            } else if (pos_minus != std::string::npos) {
                sign_pos = pos_minus;
            }

            if (sign_pos != std::string::npos && sign_pos > 0) {
                std::string real_str = complex_str.substr(0, sign_pos);
                std::string imag_str = complex_str.substr(sign_pos, pos_i - sign_pos);

                real_part = safe_stod(real_str);

                if (imag_str == "+") {
                    imag_part = 1.0;
                } else if (imag_str == "-") {
                    imag_part = -1.0;
                } else {
                    imag_part = safe_stod(imag_str);
                }
            } else {
                real_part = 0.0;
                std::string imag_str = complex_str.substr(0, pos_i); // Substring before 'i'

                if (imag_str.empty() || imag_str == "+") {
                    imag_part = 1.0;
                } else if (imag_str == "-") {
                    imag_part = -1.0;
                } else {
                    imag_part = safe_stod(imag_str);
                }
            }
        }

        std::cout << "complex " << complex_str << std::endl;
        std::cout << "the real part is " << real_part << std::endl;
        std::cout << "and the imaginary part is " << imag_part << std::endl;
    }

    return 0;
}
