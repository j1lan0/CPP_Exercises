#include "../src/pixels.hpp"
#include "../src/image.hpp"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("We can write and open images with their path")
{
    
    const size_t WIDTH = 32;
    const size_t HEIGHT = 16;

    const std::function<uint8_t(const size_t, const size_t)> foo = []
        (const size_t i, const size_t j)
    {
        return (97+ (i+j*j)%16);
    };

    {
        Image<uint8_t, WIDTH, HEIGHT> img(foo);
        //img.save("images/lol.png");
        lib::save(img, "lol.png");
        
        for (size_t j = 0; j < HEIGHT; ++j)
        {
            for (size_t i = 0; i < WIDTH; ++i)
            {
                std::cout << img(i,j) << " ";
            }
            std::cout << std::endl;
        }

    }

    std::cout << std::endl;
    {
        Image<uint8_t, WIDTH, HEIGHT> img = lib::load<uint8_t, WIDTH, HEIGHT>("lol.png");
        for (size_t j = 0; j < HEIGHT; ++j)
        {
            for (size_t i = 0; i < WIDTH; ++i)
            {
                REQUIRE(img(i,j) == foo(i,j));
                std::cout << img(i,j) << " " << std::flush;
                
            }
            std::cout << std::endl;
        }
    }
}
