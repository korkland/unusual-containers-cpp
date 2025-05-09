#include "unusual_containers/double_buffer_circular_buffer.hpp"
#include <cassert>
#include <iostream>

int main() {
    unusual_containers::DoubleBufferCircularBuffer<int, 4> buf;

    buf.push(1);
    buf.push(2);
    buf.push(3);
    buf.push(4);
    buf.push(5); // overwrite oldes

    const int* data = buf.data();
    for (std::size_t i = 0; i < buf.size(); ++i){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    assert(buf.size() == 4);
}