#!/usr/bin/env bash
set -euo pipefail
HERE="$(cd "$(dirname "$0")" && pwd)"
ROOT="$(cd "$HERE/../.." && pwd)/src"
mapfile -d '' SOURCES < <(find "$ROOT" -name '*.cpp' -print0)
BIN="$(mktemp /tmp/flprog_oled_test.XXXXXX)"
trap 'rm -f "$BIN"' EXIT
g++ -std=c++11 -Wall -Wextra -Werror=return-type -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer \
  -I"$HERE/stubs" -I"$ROOT" -I"$ROOT/Base" -I"$ROOT/Chips" \
  "$HERE/test.cpp" "${SOURCES[@]}" -o "$BIN"
ASAN_OPTIONS=detect_leaks=1:halt_on_error=1 UBSAN_OPTIONS=halt_on_error=1 "$BIN"
