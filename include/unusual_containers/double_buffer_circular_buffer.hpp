#pragma once

#include <cstddef>
#include <array>

namespace unusual_containers{

template <typename T, std::size_t N>
class DoubleBufferCircularBuffer{
    std::array<T, 2*N> _buffer;
    std::size_t _head;
    std::size_t _size;

public:
    constexpr std::size_t capacity() const noexcept { return N; }
    std::size_t size() const noexcept { return _size; }

    /// @note This function may throw if T's assignment operator throws.
    void push(const T& value){
        auto pos = (_head + _size) % N;
        _buffer[pos] = value;
        _buffer[pos + N] = value;
        if (_size < N) ++_size;
        else _head = (_head + 1) % N;
    }

    const T* data() const noexcept { return &_buffer[_head]; }
};

} // namespace unusual_containers