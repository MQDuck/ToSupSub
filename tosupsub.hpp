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

namespace tosupsub
{

static const std::string digitToSuperscript[] {
        "\u2070", // [0]  = 0
        "\u00B9", // [1]  = 1
        "\u00B2", // [2]  = 2
        "\u00B3", // [3]  = 3
        "\u2074", // [4]  = 4
        "\u2075", // [5]  = 5
        "\u2076", // [6]  = 6
        "\u2077", // [7]  = 7
        "\u2078", // [8]  = 8
        "\u2079", // [9]  = 9
        "\u207A", // [10] = +
        "\u207B", // [11] = -
        "\u22C5"  // [12] = . (sort of)
};

static const std::string digitToSubscript[] {
        "\u2080", // [0]  = 0
        "\u2081", // [1]  = 1
        "\u2082", // [2]  = 2
        "\u2083", // [3]  = 3
        "\u2084", // [4]  = 4
        "\u2085", // [5]  = 5
        "\u2086", // [6]  = 6
        "\u2087", // [7]  = 7
        "\u2088", // [8]  = 8
        "\u2089", // [9]  = 9
        "\u208A", // [10] = +
        "\u208B", // [11] = -
        "."       // [12] = . (literally)
};

template<typename I, const std::string* const digitMap>
std::string i_tosupsubscript(I number, std::string& supsubStr)
{
    I digitSize;
    for(digitSize = 10; number / digitSize; digitSize *= 10);
    for(digitSize /= 10; digitSize > 1; digitSize /= 10)
    {
        supsubStr += digitMap[number / digitSize];
        number %= digitSize;
    }
    supsubStr += digitMap[number];

    return supsubStr;
};

template<typename SI, const std::string* const digitMap>
std::string si_tosupsubcript(SI number)
{
    std::string supsubStr;
    if(number < 0)
    {
        number = -number;
        supsubStr = digitMap[11];
    }
    return i_tosupsubscript<SI, digitMap>(number, supsubStr);
};

template<typename UI, const std::string* const digitMap>
std::string ui_tosupsubcript(UI number)
{
    std::string supsubStr;
    return i_tosupsubscript<UI, digitMap>(number, supsubStr);
};

template<typename F, const std::string* const digitMap>
std::string f_tosupsubscript(F number)
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
};

} // namespace tosupsub

template<class T>
std::string tosuperscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_signed<T>::value>::type* = 0)
{
    return tosupsub::si_tosupsubcript<T, tosupsub::digitToSuperscript>(number);
}

template<class T>
std::string tosuperscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_unsigned<T>::value>::type* = 0)
{
    return tosupsub::ui_tosupsubcript<T, tosupsub::digitToSuperscript>(number);
}

template<class T>
std::string tosuperscript(const T number,
                          typename std::enable_if<std::is_floating_point<T>::value>::type* = 0)
{
    return tosupsub::f_tosupsubscript<T, tosupsub::digitToSuperscript>(number);
}

template<class T>
std::string tosubscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_signed<T>::value>::type* = 0)
{
    return tosupsub::si_tosupsubcript<T, tosupsub::digitToSubscript>(number);
}

template<class T>
std::string tosubscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_unsigned<T>::value>::type* = 0)
{
    return tosupsub::ui_tosupsubcript<T, tosupsub::digitToSubscript>(number);
}

template<class T>
std::string tosubscript(const T number,
                        typename std::enable_if<std::is_floating_point<T>::value >::type* = 0)
{
    return tosupsub::f_tosupsubscript<T, tosupsub::digitToSubscript>(number);
}

#endif //TOSUPSUB_TOSUPSUB_HPP
