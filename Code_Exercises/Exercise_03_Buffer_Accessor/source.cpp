/*
 * SYCL Quick Reference
 * ~~~~~~~~~~~~~~~~~~~~
 *
 * // Include SYCL header
 * #include <CL/sycl.hpp>
 *
 * // Default construct a queue
 * auto q = sycl::queue{};
 *
 * // Make a buffer associated with `a`
 * auto buf = sycl::buffer{&a, sycl::range<1>{1}}
 *
 * // Submit a task to the queue
 * q.submit([&](sycl::handler &cgh) {
 *   
 *   // Declaring different accessors
 *   auto read_acc = buf.get_access<sycl::access::mode::read>(bufA, cgh);
 *   auto write_acc = buf.get_access<sycl::access::mode::write>(bufB, cgh);
 *   auto read_write_acc = buf.get_access<sycl::access::mode::read_write>(bufC, cgh);
 *
 *   // submit a single task
 *   cgh.single_task([=](){
 *      // do stuff      
 *   });
 *
 * });
 *
 * // N.B. - Each call to q.submit can only contain a single command (single_task)
 *
 * // N.B. - Buffers will only update the memory they point to when they are 
 * // destroyed
 *
 */

#include <iostream>

int main() {
  int a = 1, b = 2;

  // 1. Construct a queue

  // 2. Make a buffer for a and another for b

  // 3. Use q.submit to multiply a by 2. Use accessors within q.submit
  
  // 4. Use q.submit to multiply b by 100. Use accessors within q.submit

  // 5. Use q.submit to add a and b and store the value in a. 
  
  // Use braces around steps 1-5 so that memory is updated when buffers go out
  // of scope


  if (a == 202) {
    std::cout << "Got expected answer: 202\n";
  } else {
    std::cout << "Got unexpected answer: " << a << '\n';
  }
}
