#include <iostream>
#include <exception>

#define STRIFY__(x, ...) #x
#define STRIFY_(...) STRIFY__(__VA_ARGS__, )
#define EXPECT(cond) do{if(!(cond)) throw "-> ["#cond"] failed. " __FILE__ ":" STRIFY_(__LINE__); } while(0)

#include "vec3_tests.hpp"

int main()
{
    try{
        vec3_tests();

    } catch(const std::exception e) {
        std::cout << e.what() << std::endl;
        return 1;
    } catch(const char* e) {
        std::cout << e << std::endl;
        return 1;
    } catch(...) {
        std::cout << "unkown exception" << std::endl;
        return 1;
    }

    std::cout << "[100%] pass" << std::endl;
    return 0;
}