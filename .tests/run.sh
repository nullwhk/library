#!/usr/bin/env bash

set -e

echo

clang++ "-I$(pwd)" -O2 -o runner -std=c++23 .tests/runner.cpp

./runner

rm runner
