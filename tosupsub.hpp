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
#include <cstring>
#include <map>

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

static const std::map<char, std::string> charToSuperscript {
        {'0', "\u2070"},
        {'1', "\u00B9"},
        {'2', "\u00B2"},
        {'3', "\u00B3"},
        {'4', "\u2074"},
        {'5', "\u2075"},
        {'6', "\u2076"},
        {'7', "\u2077"},
        {'8', "\u2078"},
        {'9', "\u2079"},
        {'a', "\u1D43"},
        {'b', "\u1D47"},
        {'c', "\u1D9C"},
        {'d', "\u1D48"},
        {'e', "\u1D49"},
        {'f', "\u1DA0"},
        {'g', "\u1D4D"},
        {'h', "\u02B0"},
        {'i', "\u1DA6"},
        {'j', "\u02B2"},
        {'k', "\u1D4F"},
        {'l', "\u02E1"},
        {'m', "\u1D50"},
        {'n', "\u207F"},
        {'o', "\u1D52"},
        {'p', "\u1D56"},
        {'q', "\u146B"},
        {'r', "\u02B3"},
        {'s', "\u02E2"},
        {'t', "\u1D57"},
        {'u', "\u1D58"},
        {'v', "\u1D5B"},
        {'w', "\u02B7"},
        {'x', "\u02E3"},
        {'y', "\u02B8"},
        {'z', "\u1DBB"},
        {'A', "\u1D2C"},
        {'B', "\u1D2E"},
        {'C', "\u1D9C"},
        {'D', "\u1D30"},
        {'E', "\u1D31"},
        {'F', "\u1DA0"},
        {'G', "\u1D33"},
        {'H', "\u1D34"},
        {'I', "\u1D35"},
        {'J', "\u1D36"},
        {'K', "\u1D37"},
        {'L', "\u1D38"},
        {'M', "\u1D39"},
        {'N', "\u1D38"},
        {'O', "\u1D3C"},
        {'P', "\u1D3E"},
        //{'Q', "Q"},
        {'R', "\u1D3F"},
        {'S', "\u02E2"},
        {'T', "\u1D40"},
        {'U', "\u1D41"},
        {'V', "\u2C7D"},
        {'W', "\u1D42"},
        {'X', "\u02E3"},
        {'Y', "\u02B8"},
        {'Z', "\u1DBB"},
        {'+', "\u207A"},
        {'-', "\u207B"},
        {'=', "\u207C"},
        {'.', "\u22C5"},
        {'(', "\u207D"},
        {')', "\u207E"}
};

static const std::map<char, std::string> charToSubscript {
        {'0', "\u2080"},
        {'1', "\u2081"},
        {'2', "\u2082"},
        {'3', "\u2083"},
        {'4', "\u2084"},
        {'5', "\u2085"},
        {'6', "\u2086"},
        {'7', "\u2087"},
        {'8', "\u2088"},
        {'9', "\u2089"},
        {'a', "\u2090"},
        //{'b', "b"},
        //{'c', "c"},
        //{'d', "d"},
        {'e', "\u2091"},
        //{'f', "f"},
        //{'g', "g"},
        {'h', "\u2095"},
        {'i', "\u1D62"},
        {'j', "\u2C7C"},
        {'k', "\u2096"},
        {'l', "\u2097"},
        {'m', "\u2098"},
        {'n', "\u2099"},
        {'o', "\u2092"},
        {'p', "\u209A"},
        //{'q', "q"},
        {'r', "\u1D63"},
        {'s', "\u209B"},
        {'t', "\u209C"},
        {'u', "\u1D64"},
        {'v', "\u1D65"},
        //{'w', "w"},
        {'x', "\u2093"},
        //{'y', "y"},
        //{'z', "z"},
        {'A', "\u2090"},
        //{'B', "B"},
        //{'C', "C"},
        //{'D', "D"},
        {'E', "\u2091"},
        //{'F', "F"},
        //{'G', "G"},
        {'H', "\u2095"},
        {'I', "\u1D62"},
        {'J', "\u2C7C"},
        {'K', "\u2096"},
        {'L', "\u2097"},
        {'M', "\u2098"},
        {'N', "\u2099"},
        {'O', "\u2092"},
        {'P', "\u209A"},
        //{'Q', "Q"},
        {'R', "\u1D63"},
        {'S', "\u209B"},
        {'T', "\u209C"},
        {'U', "\u1D64"},
        {'V', "\u1D65"},
        //{'W', "W"},
        {'X', "\u2093"},
        //{'Y', "Y"},
        //{'Z', "Z"},
        {'+', "\u208A"},
        {'-', "\u208B"},
        //{'.', "."},
        {'=', "\u208C"},
        {'(', "\u208D"},
        {')', "\u208E"}
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
}

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
}

template<typename UI, const std::string* const digitMap>
std::string ui_tosupsubcript(UI number)
{
    std::string supsubStr;
    return i_tosupsubscript<UI, digitMap>(number, supsubStr);
}

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
}

template<const std::map<char, std::string>& charMap>
std::string s_tosupsubscript(const std::string& numStr)
{
    std::string supsubStr;
    for(char ch : numStr)
    {
        /*if(charMap.count(ch))
            supsubStr += charMap.at(ch);
        else
            supsubStr += ch;*/
        auto supsubChar = charMap.find(ch);
        if(supsubChar == charMap.end())
            supsubStr += ch;
        else
            supsubStr += supsubChar->second;
    }
    return supsubStr;
}

} // namespace tosupsub

template<class SI>
std::string tosuperscript(const SI number,
                          typename std::enable_if<std::is_integral<SI>::value>::type* = 0,
                          typename std::enable_if<std::is_signed<SI>::value>::type* = 0)
{
    return tosupsub::si_tosupsubcript<SI, tosupsub::digitToSuperscript>(number);
}

template<class UI>
std::string tosuperscript(const UI number,
                          typename std::enable_if<std::is_integral<UI>::value>::type* = 0,
                          typename std::enable_if<std::is_unsigned<UI>::value>::type* = 0)
{
    return tosupsub::ui_tosupsubcript<UI, tosupsub::digitToSuperscript>(number);
}

template<class F>
std::string tosuperscript(const F number,
                          typename std::enable_if<std::is_floating_point<F>::value>::type* = 0)
{
    return tosupsub::f_tosupsubscript<F, tosupsub::digitToSuperscript>(number);
}

std::string tosuperscript(const std::string& numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSuperscript>(numStr);
}

std::string tosuperscript(const std::string&& numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSuperscript>(numStr);
}

template<class SI>
std::string tosubscript(const SI number,
                        typename std::enable_if<std::is_integral<SI>::value>::type* = 0,
                        typename std::enable_if<std::is_signed<SI>::value>::type* = 0)
{
    return tosupsub::si_tosupsubcript<SI, tosupsub::digitToSubscript>(number);
}

template<class UI>
std::string tosubscript(const UI number,
                        typename std::enable_if<std::is_integral<UI>::value>::type* = 0,
                        typename std::enable_if<std::is_unsigned<UI>::value>::type* = 0)
{
    return tosupsub::ui_tosupsubcript<UI, tosupsub::digitToSubscript>(number);
}

template<class F>
std::string tosubscript(const F number,
                        typename std::enable_if<std::is_floating_point<F>::value >::type* = 0)
{
    return tosupsub::f_tosupsubscript<F, tosupsub::digitToSubscript>(number);
}

std::string tosubscript(const std::string& numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSubscript>(numStr);
}

std::string tosubscript(const std::string&& numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSubscript>(numStr);
}

#endif //TOSUPSUB_TOSUPSUB_HPP
