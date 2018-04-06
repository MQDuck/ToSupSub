/*
 * ToSupSub
 * https://github.com/Subhipster-Collective/ToSupSub
 *
 * Licensed under the MIT License <http://opensource.org/licenses/MIT>.
 * Copyright © 2018 Jeffrey Thomas Piercy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "tosupsub.hpp"

static const std::string digitToSuperscript[] {
    "\u2070", // 0
    "\u00B9", // 1
    "\u00B2", // 2
    "\u00B3", // 3
    "\u2074", // 4
    "\u2075", // 5
    "\u2076", // 6
    "\u2077", // 7
    "\u2078", // 8
    "\u2079", // 9
    "\u207A", // +
    "\u207B", // -
    "\u22C5"  // . (sort of)
};

static const std::string digitToSubscript[] {
    "\u2080", // 0
    "\u2081", // 1
    "\u2082", // 2
    "\u2083", // 3
    "\u2084", // 4
    "\u2085", // 5
    "\u2086", // 6
    "\u2087", // 7
    "\u2088", // 8
    "\u2089", // 9
    "\u208A", // +
    "\u208B", // -
    "."       // . (literally)
};

std::string tosupsubscript(unsigned long long int number, const bool isNegative, const std::string* const digitMap)
{
    unsigned long long int digitSize;
    std::string supsubStr;

    if(isNegative)
        supsubStr = digitMap[11];
    for(digitSize = 10; number / digitSize; digitSize *= 10);
    for(digitSize /= 10; digitSize > 0; digitSize /= 10)
    {
        long long int digit = number / digitSize;
        supsubStr += digitMap[digit];
        number %= (digit * digitSize);
    }

    return supsubStr;
}

std::string tosupsubscript(const long double number, const std::string* const digitMap)
{
    std::string numStr = std::to_string(number);
    std::string supsubStr;
    for(char& d : numStr)
    {
        switch(d)
        {
            case '+':
                supsubStr += digitMap[10];
                break;
            case '-':
                supsubStr += digitMap[11];
                break;
            case '.':
                supsubStr += digitMap[12];
                break;
            default:
                supsubStr += digitMap[d - '0'];
        }
    }

    return supsubStr;
}

std::string tosuperscript(const long long int number)
{
    if(number < 0)
        return tosupsubscript(static_cast<const unsigned long long int>(-number), true, digitToSuperscript);
    else
        return tosupsubscript(static_cast<const unsigned long long int>(number), false, digitToSuperscript);
}

std::string tosuperscript(const unsigned long long int number)
{
    return tosupsubscript(number, false, digitToSuperscript);
}

std::string tosuperscript(const long int number)
{
    return tosuperscript(static_cast<const long long int>(number));
}

std::string tosuperscript(const unsigned long int number)
{
    return tosuperscript(static_cast<const unsigned long long int>(number));
}

std::string tosuperscript(const int number)
{
    return tosuperscript(static_cast<const long long int>(number));
}

std::string tosuperscript(const unsigned int number)
{
    return tosuperscript(static_cast<const unsigned long long int>(number));
}

std::string tosuperscript(const long double number)
{
    return tosupsubscript(number, digitToSuperscript);
}

std::string tosuperscript(const double number)
{
    return tosuperscript(static_cast<const long double>(number));
}

std::string tosubscript(const long long int number)
{
    if(number < 0)
        return tosupsubscript(static_cast<const unsigned long long int>(-number), true, digitToSubscript);
    else
        return tosupsubscript(static_cast<const unsigned long long int>(number), false, digitToSubscript);
}

std::string tosubscript(const unsigned long long int number)
{
    return tosupsubscript(number, false, digitToSubscript);
}

std::string tosubscript(const long int number)
{
    return tosubscript(static_cast<const long long int>(number));
}

std::string tosubscript(const unsigned long int number)
{
    return tosubscript(static_cast<const unsigned long long int>(number));
}

std::string tosubscript(const int number)
{
    return tosubscript(static_cast<const long long int>(number));
}

std::string tosubscript(const unsigned int number)
{
    return tosubscript(static_cast<const unsigned long long int>(number));
}

std::string tosubscript(const long double number)
{
    return tosupsubscript(number, digitToSubscript);
}

std::string tosubscript(const double number)
{
    return tosubscript(static_cast<const long double>(number));
}
