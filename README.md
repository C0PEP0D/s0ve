# s0ve : Simple C++ data saving library

[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

A simple C++ library that helps saving data into ASCII files.

This simple C++ library provides helpers to save data into ASCII files. Supports the CSV format.
Simple examples are provided and should be enough to explain how to use this library.

This repository contains:

1. The software itself provided as a header only library in the directory [include/s0ve](./include/s0ve)
2. A few [examples](./examples).

## Table of Contents

- [Background](#background)
- [Install](#install)
- [License](#license)

## Background

This library has been produced during my PhD thesis and as part as the European Research Council project: [C0PEP0D](https://c0pep0d.github.io/)
This library is used as part of [SHELD0N](https://github.com/C0PEP0D/sheld0n), a lagrangian particle advection software.

## Install

### Dependencies

* [**CMake** `v?`](https://cmake.org/download/) or higher must be installed
* a c++17 compliant compiler, such as [**gcc** `v9`](https://gcc.gnu.org/) or higher must be installed. For Ubuntu users: [ppa](https://launchpad.net/%7Ejonathonf/+archive/ubuntu/gcc?field.series_filter=bionic).

### Installing

Start by cloning this repository.

```sh
$ git clone https://github.com/C0PEP0D/s0ve.git
```

### Examples

Running an example:

```bash
$ cd examples/csv
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./csv
```

### Updating

A simple pull should be enough.

```sh
$ git pull
```

## Maintainers

Rémi Monthiller - [@rmonthil](https://gitlab.com/rmonthil) - remi.monthiller@gmail.com

## Contributing

Feel free to dive in! [Open an issue](https://github.com/rmonthil/c0pep0d/issues/new) or submit PRs.

## License

[MIT © Centrale Marseille, Rémi MONTHILLER.](./LICENSE)
