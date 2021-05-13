#! /usr/bin/env python3

import sys
import random


class DataGenerator():
    def __init__(self, names, likes, age_min, age_max):
        self.__name_source = self.__load_list(names)
        self.__likes_source = self.__load_list(likes)
        self.__age_min = int(age_min, 10)
        self.__age_max = int(age_max, 10)

    def __load_list(self, path):
        with open(path, "r") as file:
            return [ line.strip('\n') for line in file]

    def __gen_age(self):
        return random.randrange(self.__age_min, self.__age_max)

    def __gen_like(self):
        return self.__likes_source[random.randrange(0,len(self.__likes_source))]

    def __gen_name(self):
        return self.__name_source[random.randrange(0,len(self.__name_source))]

    def genlist(self, count):
        for i in range(int(count, 10)):
            print("%s,%d,%s" % (self.__gen_name(), self.__gen_age(), self.__gen_like()))

if __name__ == "__main__":

    if len(sys.argv) != 6:
        print("usage: %s <name_path> <likes_path> <age_min> <age_max> <count>" % sys.argv[0])
        exit(-1)

    generator = DataGenerator(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
    generator.genlist(sys.argv[5])