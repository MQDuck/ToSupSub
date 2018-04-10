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
            {'0', "⁰"},
            {'1', "¹"},
            {'2', "²"},
            {'3', "³"},
            {'4', "⁴"},
            {'5', "⁵"},
            {'6', "⁶"},
            {'7', "⁷"},
            {'8', "⁸"},
            {'9', "⁹"},
            {'a', "ᵃ"},
            {'b', "ᵇ"},
            {'c', "ᶜ"},
            {'d', "ᵈ"},
            {'e', "ᵉ"},
            {'f', "ᶠ"},
            {'g', "ᵍ"},
            {'h', "ʰ"},
            {'i', "ᶦ"},
            {'j', "ʲ"},
            {'k', "ᵏ"},
            {'l', "ˡ"},
            {'m', "ᵐ"},
            {'n', "ⁿ"},
            {'o', "ᵒ"},
            {'p', "ᵖ"},
            {'q', "ᑫ"},
            {'r', "ʳ"},
            {'s', "ˢ"},
            {'t', "ᵗ"},
            {'u', "ᵘ"},
            {'v', "ᵛ"},
            {'w', "ʷ"},
            {'x', "ˣ"},
            {'y', "ʸ"},
            {'z', "ᶻ"},
            {'A', "ᴬ"},
            {'B', "ᴮ"},
            {'C', "ᶜ"},
            {'D', "ᴰ"},
            {'E', "ᴱ"},
            {'F', "ᶠ"},
            {'G', "ᴳ"},
            {'H', "ᴴ"},
            {'I', "ᴵ"},
            {'J', "ᴶ"},
            {'K', "ᴷ"},
            {'L', "ᴸ"},
            {'M', "ᴹ"},
            {'N', "ᴺ"},
            {'O', "ᴼ"},
            {'P', "ᴾ"},
            {'Q', "Q"},
            {'R', "ᴿ"},
            {'S', "ˢ"},
            {'T', "ᵀ"},
            {'U', "ᵁ"},
            {'V', "ⱽ"},
            {'W', "ᵂ"},
            {'X', "ˣ"},
            {'Y', "ʸ"},
            {'Z', "ᶻ"},
            {'+', "⁺"},
            {'-', "⁻"},
            {'=', "⁼"},
            {'.', "⋅"},
            {'(', "⁽"},
            {')', "⁾"}
    };

    static const std::map<char, std::string> charToSubscript {
            {'0', "₀"},
            {'1', "₁"},
            {'2', "₂"},
            {'3', "₃"},
            {'4', "₄"},
            {'5', "₅"},
            {'6', "₆"},
            {'7', "₇"},
            {'8', "₈"},
            {'9', "₉"},
            {'a', "ₐ"},
            {'b', "b"},
            {'c', "c"},
            {'d', "d"},
            {'e', "ₑ"},
            {'f', "f"},
            {'g', "g"},
            {'h', "ₕ"},
            {'i', "ᵢ"},
            {'j', "ⱼ"},
            {'k', "ₖ"},
            {'l', "ₗ"},
            {'m', "ₘ"},
            {'n', "ₙ"},
            {'o', "ₒ"},
            {'p', "ₚ"},
            {'q', "q"},
            {'r', "ᵣ"},
            {'s', "ₛ"},
            {'t', "ₜ"},
            {'u', "ᵤ"},
            {'v', "ᵥ"},
            {'w', "w"},
            {'x', "ₓ"},
            {'y', "y"},
            {'z', "z"},
            {'A', "ₐ"},
            {'B', "B"},
            {'C', "C"},
            {'D', "D"},
            {'E', "ₑ"},
            {'F', "F"},
            {'G', "G"},
            {'H', "ₕ"},
            {'I', "ᵢ"},
            {'J', "ⱼ"},
            {'K', "ₖ"},
            {'L', "ₗ"},
            {'M', "ₘ"},
            {'N', "ₙ"},
            {'O', "ₒ"},
            {'P', "ₚ"},
            {'Q', "Q"},
            {'R', "ᵣ"},
            {'S', "ₛ"},
            {'T', "ₜ"},
            {'U', "ᵤ"},
            {'V', "ᵥ"},
            {'W', "W"},
            {'X', "ₓ"},
            {'Y', "Y"},
            {'Z', "Z"},
            {'+', "₊"},
            {'-', "₋"},
            {'.', "."},
            {'=', "₌"},
            {'(', "₍"},
            {')', "₎"}
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
    std::string s_tosupsubscript(const char* const numStr, const size_t length)
    {
        std::string supsubStr;
        for(size_t i = 0; i < length; ++i)
        {
            if(charMap.count(numStr[i]))
                supsubStr += charMap.at(numStr[i]);
            else
                supsubStr += numStr[i];
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

std::string tosuperscript(const char* const numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSuperscript>(numStr, std::strlen(numStr));
}

std::string tosuperscript(const std::string& numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSuperscript>(numStr.data(), numStr.length());
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

std::string tosubscript(const char* const numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSubscript>(numStr, std::strlen(numStr));
}

std::string tosubscript(const std::string& numStr)
{
    return tosupsub::s_tosupsubscript<tosupsub::charToSubscript>(numStr.data(), numStr.length());
}

#endif //TOSUPSUB_TOSUPSUB_HPP
