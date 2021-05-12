/*
 * File:   Rectangle.c
 * Author: Pooh
 *
 * Created on May 12, 2021
 */

#include <stdlib.h>

#include "Rectangle.h"

static RECT_T* create(int width, int height);
static void destory(RECT_T* rect);
static bool set_values(RECT_T* rect, int width,int height);
static int get_area(RECT_T* rect);

RectangleInterface Rectangle = {

    .create = create,
    .destroy = destory,
    .set_values = set_values,
    .get_area = get_area

};

static RECT_T* create(int width, int height){
    RECT_T* rect = (RECT_T*)malloc(sizeof(RECT_T));
    if(rect != NULL){
        set_values(rect, width, height);
    }
    
    return rect;
}

static void destory(RECT_T* rect){
    if(rect != NULL) free(rect);
}

static bool set_values(RECT_T* rect, int width,int height){

    if(rect == NULL){
        return false;
    }

    if( width <= 0 || height <= 0){
        rect->width = 0;
        rect->height = 0;

        return false;
    }

    rect->width = width;
    rect->height = height;

    return true;
    
}

static int get_area(RECT_T* rect){
    if(rect == NULL|| rect->width <= 0 || rect->height <= 0){
        return -1;
    } 

    return rect->width  * rect->height;

}
