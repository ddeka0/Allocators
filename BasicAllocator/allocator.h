#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <glog/logging.h>
#include <iostream>

namespace BasicAllocator {

template <typename DataType>
class Allocator {
 public:
  using value_type = DataType;
  Allocator() = default;

  template <class U>
  constexpr Allocator(const Allocator<U>&) noexcept {
    LOG(INFO);
  }

  void deallocate(DataType* p, std::size_t n) {
    free(p);
    LOG(INFO) << "deallocation done. p = " << p << ", size = " << n;
    report(p, n, 0);
  }

  DataType* allocate(std::size_t n) {
    LOG(INFO) << "DataType Size = " << sizeof(DataType);
    DataType* p = (DataType*)malloc(n * sizeof(DataType));
    LOG(INFO) << "allocation done. p = " << p << ", size = " << n;
    report(p, n);
    return p;
  }

 private:
  void report(DataType* p, std::size_t n, bool alloc = true) const {
    std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(DataType) * n
              << " bytes at " << std::hex << std::showbase
              << reinterpret_cast<void*>(p) << std::dec << '\n';
  }
};

}  // namespace BasicAllocator

#endif  // ALLOCATOR_H_
