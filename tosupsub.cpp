/*
 * To SuperSubScript
 * https://github.com/Subhipster-Collective/To-Superscript
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
    "\u207B"  // -
};

static const std::string digitToSubscript[] {
    "\u2080" // 0
    "\u2081" // 1
    "\u2082" // 2
    "\u2083" // 3
    "\u2084" // 4
    "\u2085" // 5
    "\u2086" // 6
    "\u2087" // 7
    "\u2088" // 8
    "\u2089" // 9
    "\u208A" // +
    "\u208B" // -
};

std::string tosuperscript(long long int number)
{
    bool isNegative;
    size_t numDigits;
    long long int digitSize;
    std::string superStr;

    if(number < 0)
    {
        number = -number;
        superStr = digitToSuperscript[11];
    }
    else
        isNegative = false;

    for(digitSize = 10; number / digitSize; digitSize *= 10);
    for(digitSize /= 10; digitSize > 0; digitSize /= 10)
    {
        long long int digit = number / digitSize;
        superStr += digitToSuperscript[digit];
        number %= (digit * digitSize);
    }

    return superStr;
}
