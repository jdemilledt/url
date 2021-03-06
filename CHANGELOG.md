# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.0] - 2018-10-13
### Added
- Conversion functions between ``skyr::url`` and ``std::filesystem::path`` 

### Changed
- Improved license attributions
- Minor API improvements
- Improved build and installation instructions in README.md


## [0.5] - 2018-09-30
### Added
- A ``skyr::url`` class that implements a generic URL parser,
  compatible with the [WhatWG URL specification](https://url.spec.whatwg.org/#url-class)
- URL serialization and comparison
- Percent encoding and decoding functions
- IDNA and Punycode functions for domain name parsing
