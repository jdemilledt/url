// Copyright 2017-18 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <algorithm>
#include "url_schemes.hpp"

namespace skyr {
namespace details {
const default_port_list &special_schemes() noexcept {
  static const auto schemes = default_port_list{
    {"ftp", 21},
    {"file", nullopt},
    {"gopher", 70},
    {"http", 80},
    {"https", 443},
    {"ws", 80},
    {"wss", 443},
  };
  return schemes;
}

optional<std::uint16_t> default_port(std::string_view scheme) noexcept {
  auto schemes = special_schemes();
  auto first = begin(schemes), last = end(schemes);
  auto it = std::find_if(
      first, last,
      [&scheme](const std::pair<std::string, optional<std::uint16_t>>
                    &special_scheme) -> bool {
        return scheme.compare(special_scheme.first) == 0;
      });
  if (it != last) {
    return it->second;
  }
  return nullopt;
}

bool is_special(std::string_view scheme) noexcept {
  auto schemes = special_schemes();
  auto first = begin(schemes), last = end(schemes);
  auto it = std::find_if(
      first, last,
      [&scheme](const std::pair<std::string, optional<std::uint16_t>>
                &special_scheme) -> bool {
        return scheme.compare(special_scheme.first) == 0;
      });
  return (it != last);
}

bool is_default_port(std::string_view scheme, std::uint16_t port) noexcept {
  auto dport = default_port(scheme);
  return dport && (dport.value() == port);
}
}  // namespace details
}  // namespace skyr
