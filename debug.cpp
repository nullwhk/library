#pragma once

#include <bitset>
#include <complex>
#include <concepts>
#include <cstddef>
#include <format>
#include <iostream>
#include <iterator>
#include <ostream>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace debug {

    namespace traits {

        template <typename T>
        concept has_fmt = requires(T val) {
            { val._fmt() } -> std::convertible_to<std::string>;
        };

        template <typename T>
        concept is_map = std::ranges::input_range<T> && requires {
            typename T::key_type;
            typename T::mapped_type;
            typename T::value_type;
        };

        template <typename T>
        concept is_seq = std::ranges::input_range<T> && requires {
            typename T::value_type;
        } && !requires {
            typename T::key_type;
        } && !std::convertible_to<T, std::string_view>;

        template <typename T>
        concept is_set = std::ranges::input_range<T> && requires {
            typename T::key_type;
            typename T::value_type;
        } && !requires {
            typename T::mapped_type;
        };

    }

    std::string fmt(std::floating_point auto);
    std::string fmt(std::integral auto);
    std::string fmt(const traits::has_fmt auto&);
    std::string fmt(const traits::is_map auto&);
    std::string fmt(const traits::is_seq auto&);
    std::string fmt(const traits::is_set auto&);

    template <std::size_t N>
    std::string fmt(const std::bitset<N>&);

    template <typename T>
    std::string fmt(const std::complex<T>&);

    template <typename T1, typename T2>
    std::string fmt(const std::pair<T1, T2>&);

    template <typename... Ts>
    std::string fmt(const std::priority_queue<Ts...>&);

    template <typename... Ts>
    std::string fmt(const std::queue<Ts...>&);

    template <typename... Ts>
    std::string fmt(std::stack<Ts...>);

    std::string fmt(char);
    std::string fmt(const char*);
    std::string fmt(const std::string&);
    std::string fmt(const std::vector<bool>&);

    template <std::input_iterator It>
    std::string fmt(It, It);

    template <typename T>
    std::string fmt(T, std::invocable<const T&> auto);

    template <typename T>
    std::string cmb(const T& val) {

        return fmt(val);

    }

    template <typename T, typename... Ts>
    std::string cmb(const T& val, const Ts&... rest) {

        return fmt(val) + ',' + ' ' + fmt(rest...);

    }

    std::string fmt(std::floating_point auto val) {

        return std::format("{:.6f}", val);

    }

    std::string fmt(std::integral auto val) {

        return std::to_string(val);

    }

    std::string fmt(const traits::has_fmt auto& val) {

        return val._fmt();

    }

    std::string fmt(const traits::is_map auto& val) {

        std::string str;

        for (auto it = std::begin(val); it != std::end(val); ++it) {
            str.append(fmt(it->first) + ':' + ' ' + fmt(it->second));
            if (std::next(it) != std::end(val)) {
                str.append(", ");
            }
        }

        return '{' + str + '}';

    }

    std::string fmt(const traits::is_seq auto& val) {

        return '[' + fmt(std::begin(val), std::end(val)) + ']';

    }

    std::string fmt(const traits::is_set auto& val) {

        return '{' + fmt(std::begin(val), std::end(val)) + '}';

    }

    template <std::size_t N>
    std::string fmt(const std::bitset<N>& val) {

        return val.to_string();

    }

    template <typename T>
    std::string fmt(const std::complex<T>& val) {

        const T imag = std::imag(val);

        return fmt(
            std::real(val)
        ) + ' ' + (imag >= 0 ? '+' : '-') + ' ' + fmt(std::abs(imag)) + 'i';

    }

    template <typename T1, typename T2>
    std::string fmt(const std::pair<T1, T2>& val) {

        return '(' + cmb(val.first, val.second) + ')';

    }

    template <typename... Ts>
    std::string fmt(const std::priority_queue<Ts...>& val) {

        return fmt(
            val, [](const std::priority_queue<Ts...>& cont) {
                return cont.top();
            }
        );

    }

    template <typename... Ts>
    std::string fmt(const std::queue<Ts...>& val) {

        return fmt(
            val, [](const std::queue<Ts...>& cont) {
                return cont.front();
            }
        );

    }

    template <typename... Ts>
    std::string fmt(std::stack<Ts...> val) {

        std::stack<Ts...> stk;

        while (!std::empty(val)) {
            stk.push(val.top());
            val.pop();
        }

        return fmt(
            stk, [](const std::stack<Ts...>& cont) {
                return cont.top();
            }
        );

    }

    std::string fmt(char val) {

        return std::string({val});

    }

    std::string fmt(const char* val) {

        return std::string(val);

    }

    std::string fmt(const std::string& val) {

        return val;

    }

    std::string fmt(const std::vector<bool>& val) {

        return fmt(std::vector<short>(std::begin(val), std::end(val)));

    }

    template <std::input_iterator It>
    std::string fmt(It it_l, It it_r) {

        std::string str;

        while (it_l != it_r) {
            str.append(fmt(*it_l));
            if (std::next(it_l) != it_r) {
                str.append(", ");
            }
            ++it_l;
        }

        return str;

    }

    template <typename T>
    std::string fmt(T val, std::invocable<const T&> auto f) {

        std::string str;

        while (!std::empty(val)) {
            str.append(fmt(f(val)));
            val.pop();
            if (!std::empty(val)) {
                str.append(", ");
            }
        }

        return '[' + str + ']';

    }

}

void dbg() {

    std::clog << '\n' << std::flush;

}

template <typename T>
void dbg(const T& val) {

    std::clog << debug::fmt(val) << '\n' << std::flush;

}

template <typename T, typename... Ts>
void dbg(const T& val, const Ts&... rest) {

    std::clog << debug::fmt(val) << ' ';

    dbg(rest...);

}
