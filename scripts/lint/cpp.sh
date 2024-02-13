cpplint --filter="
  +build/c++14,
  -build/namespaces,
  -legal/copyright,
  -runtime/int,
  -runtime/string
  " source/**/*.cpp
