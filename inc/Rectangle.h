/*
 * File:   Rectangle.h
 * Author: Pooh
 *
 * Trying to emulate a C+ Rectangle class from C...  private is not possible in C so that much is lost.
 * The RECT* paramter to the interface methods is reminisent of how Python handle this (self) 
 * 
 * Create adn Destroy methods are provided for dynamic allocation and management. Sorta like new and delete
 * but not quite as useful...  
 * 
 * Created on May 12, 2021
 */

 #ifndef Rectangle_H
 #define Rectangle_H

#include <stdbool.h>

typedef struct{
    int width;
    int height;
}RECT_T; 

typedef struct {

    RECT_T* (*create)(int width, int height);
    void (*destroy)(RECT_T* rect);

    bool (*set_values)(RECT_T* rect, int width,int height);
    int (*get_area)(RECT_T* rect);

}RectangleInterface;

extern RectangleInterface Rectangle;




 #endif  //Rectangle_H
