//
// Created by dimag on 02.12.2020.
//
#ifndef III_LAB_MODEL_H
#define III_LAB_MODEL_H
enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Model
{
public:
    static const int SIZE = 4;
    static const int ARRAY_SIZE = SIZE * SIZE;
    static const int FIELD_SIZE = 500;
    static const int CELL_SIZE = 120;
protected:
    int elements[ARRAY_SIZE];
    int empty_index;
    bool solved;
public:
    Model();
    void Init();
    bool Check();
    void Move(Direction direction);
    bool IsSolved();
    int* Elements();
};
#endif //III_LAB_MODEL_H
