#include <emath/vec3.hpp>

auto vec3_tests() -> void
{
    // default vec3
    {
        emath::vec3 a;
        EXPECT(a.x == 0);
        EXPECT(a.y == 0);
        EXPECT(a.z == 0);
    }

    // ctor vec(float)
    {
        emath::vec3 a(1.0f);
        EXPECT(a.x == 1.0f);
        EXPECT(a.y == 1.0f);
        EXPECT(a.z == 1.0f);
    }
}