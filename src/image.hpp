#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>

template<typename P, size_t W, size_t H>
class Image
{
    public:
        Image() = default;

        Image(const P & pix){
            for(size_t i = 0; i < H;i++){
                for(size_t j = 0; j < W;j++){
                    pixels[i][j] = pix;
                }
            }

        }

        P & operator()(const size_t i, const size_t j){
            return pixels[j][i];
        }

        const P & operator()(const size_t i, const size_t j) const{
            return pixels[j][i];
        }

        Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
        {       
            for(size_t j = 0; j < H;j++){
                for(size_t i = 0; i < W;i++){
                    pixels[j][i] = functor(i,j);
                }
            }
        }



    private:
        std::array<std::array<P, W>, H> pixels;
};
template<typename A,typename B, size_t W, size_t H>
Image<A,W,H> operator+(const Image<A,W,H>& lhs,const Image<B,W,H>& rhs){
    Image<A,W,H> img;
    for(size_t j = 0; j < H;j++){
        for(size_t i = 0; i < W;i++){
            img(i,j) = lhs(i,j)+ rhs(i,j);
        }
    }
    return img;
}