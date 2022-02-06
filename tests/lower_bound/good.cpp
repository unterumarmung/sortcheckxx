// Copyright 2022 Yury Gribov
// 
// Use of this source code is governed by MIT license that can be
// found in the LICENSE.txt file.

#include <algorithm>
#include <vector>

// Use non-default comparison to trigger instrumentation
struct Compare {
  bool operator()(int lhs, int rhs) {
    return lhs < rhs;
  }
};

int main() {
  std::vector<int> v;
  v.push_back(0);
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  std::lower_bound(v.begin(), v.end(), 10, Compare());
  return 0;
}
