#include <emath/mat2.hpp>

auto mat2_tests() -> void
{
    // operator==
    {
        emath::mat2 a, b;
        EXPECT(a == b);
    }
}