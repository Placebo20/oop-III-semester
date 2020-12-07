//
// Created by dimag on 02.12.2020.
//
#include "Model.h"

Model::Model()
{
    Init();
}

void Model::Init()
{
    for (int i = 0; i < ARRAY_SIZE - 1; i++) elements[i] = i + 1;

    empty_index = ARRAY_SIZE - 1;
    elements[empty_index] = 0;
    solved = true;
}

bool Model::Check()
{
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        if (elements[i] > 0 && elements[i] != i + 1) return false;
    }
    return true;
}

void Model::Move(Direction direction)
{
    int col = empty_index % SIZE;
    int row = empty_index / SIZE;

    int move_index = -1;
    if (direction == Direction::Left && col < (SIZE - 1)) move_index = empty_index + 1;
    if (direction == Direction::Right && col > 0) move_index = empty_index - 1;
    if (direction == Direction::Up && row < (SIZE - 1)) move_index = empty_index + SIZE;
    if (direction == Direction::Down && row > 0) move_index = empty_index - SIZE;

    if (empty_index >= 0 && move_index >= 0)
    {
        int tmp = elements[empty_index];
        elements[empty_index] = elements[move_index];
        elements[move_index] = tmp;
        empty_index = move_index;
    }
    solved = Check();
}

void Model::Move(Direction direction){ return solved; }

int *Model::Elements() { return elements; }
