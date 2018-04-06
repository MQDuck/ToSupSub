/*
 * ToSupSub
 * https://github.com/Subhipster-Collective/ToSupSub
 *
 * Licensed under the MIT License <http://opensource.org/licenses/MIT>.
 * Copyright © 2018 Jeffrey Thomas Piercy
 */

#ifndef TOSUPSUB_TOSUPSUB_HPP
#define TOSUPSUB_TOSUPSUB_HPP

#include <string>

std::string tosuperscript(const long long int number);
std::string tosuperscript(const unsigned long long int number);
std::string tosuperscript(const long int number);
std::string tosuperscript(const unsigned long int number);
std::string tosuperscript(const int number);
std::string tosuperscript(const unsigned int number);
std::string tosuperscript(const long double number);
std::string tosuperscript(const double number);

std::string tosubscript(const long long int number);
std::string tosubscript(const unsigned long long int number);
std::string tosubscript(const long int number);
std::string tosubscript(const unsigned long int number);
std::string tosubscript(const int number);
std::string tosubscript(const unsigned int number);
std::string tosubscript(const long double number);
std::string tosubscript(const double number);

#endif //TOSUPSUB_TOSUPSUB_HPP
