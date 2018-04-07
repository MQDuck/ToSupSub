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

namespace
{
#include "tosupsubscript_templates.hpp"
} // anonymous namespace

template<class T>
std::string tosuperscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_signed<T>::value>::type* = 0)
{
    return si_tosupsubcript<T, digitToSuperscript>(number);
}

template<class T>
std::string tosuperscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_unsigned<T>::value>::type* = 0)
{
    return ui_tosupsubcript<T, digitToSuperscript>(number);
}

template<class T>
std::string tosuperscript(const T number, typename std::enable_if<std::is_floating_point<T>::value >::type* = 0)
{
    return f_tosupsubscript<T, digitToSuperscript>(number);
}

template<class T>
std::string tosubscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_signed<T>::value>::type* = 0)
{
    return si_tosupsubcript<T, digitToSubscript>(number);
}

template<class T>
std::string tosubscript(const T number,
                          typename std::enable_if<std::is_integral<T>::value>::type* = 0,
                          typename std::enable_if<std::is_unsigned<T>::value>::type* = 0)
{
    return ui_tosupsubcript<T, digitToSubscript>(number);
}

template<class T>
std::string tosubscript(const T number, typename std::enable_if<std::is_floating_point<T>::value >::type* = 0)
{
    return f_tosupsubscript<T, digitToSubscript>(number);
}

#endif //TOSUPSUB_TOSUPSUB_HPP
