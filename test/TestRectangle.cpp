/*
 * File:   TestPeople.cpp
 * Author: Pooh
 *
 * Created on May 12, 2021
 */

#include <boost/test/unit_test.hpp>

#include "Rectangle.h"

BOOST_AUTO_TEST_CASE( RectangleTest_static ){

    RECT_T rect;
    bool result = Rectangle.set_values(&rect, 10, 20);

    BOOST_CHECK(result);
    BOOST_CHECK_EQUAL(rect.width, 10);
    BOOST_CHECK_EQUAL(rect.height, 20);
    BOOST_CHECK_EQUAL(Rectangle.get_area(&rect), 200);

    result = Rectangle.set_values(&rect, 0, 20);

    BOOST_CHECK(!result);
    BOOST_CHECK_EQUAL(rect.width, 0);
    BOOST_CHECK_EQUAL(rect.height, 0);
    BOOST_CHECK_EQUAL(Rectangle.get_area(&rect), -1);


}


BOOST_AUTO_TEST_CASE( RectangleTest_dynamic ){

    RECT_T* rect = Rectangle.create( 10, 20);

    BOOST_CHECK(rect != NULL);
    BOOST_CHECK_EQUAL(rect->width, 10);
    BOOST_CHECK_EQUAL(rect->height, 20);
    BOOST_CHECK_EQUAL(Rectangle.get_area(rect), 200);

    Rectangle.destroy(rect);

}
