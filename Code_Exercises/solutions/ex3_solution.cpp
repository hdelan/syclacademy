#include <sycl/sycl.hpp>

#include <CL/sycl.hpp>
#include <iostream>

int main() {

  int a = 1, b = 2;
  // Construct a queue
  auto q = sycl::queue{};

  {
    // Construct buffers associated with a, b
    auto bufA = sycl::buffer{&a, sycl::range<1>{1}};
    auto bufB = sycl::buffer{&b, sycl::range<1>{1}};

    // Multiply a by 2.
    q.submit([&](sycl::handler &cgh) {
      auto accA = bufA.get_access<sycl::access::mode::read_write>(cgh);
      cgh.single_task([=]() { accA[0] *= 2; });
    });
    
    // Multiply b_dev by 100.
    q.submit([&](sycl::handler &cgh) {
      auto accB = bufB.get_access<sycl::access::mode::read_write>(cgh);
      cgh.single_task([=]() { accB[0] *= 100; });
    });

    q.submit([&](sycl::handler &cgh) {
      auto accA = bufA.get_access<sycl::access::mode::read_write>(cgh);
      auto accB = bufB.get_access<sycl::read_only>(cgh);
      cgh.single_task([=]() { accA[0] += accB[0]; });
    }); 
  } // Memory is updated once buffers are destroyed

  if (a == 202) {
    std::cout << "Got expected answer: 202\n";
  } else {
    std::cout << "Got unexpected answer: " << a << '\n';
  }
}

