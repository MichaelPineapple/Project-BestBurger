#pragma once
#include "LTORG/Ass/Ass.h"
#include "Containers/UnrealString.h"
#include <random>

/* Structure which holds two integer values. Mostly used for chunk positioning */
struct cPos
{
public:
int i = 0, j = 0;
    cPos(int _i, int _j) { this->i = _i; this->j = _j; }
    cPos() { this->i = 0; this->j = 0; }
    bool operator ==(cPos _rhs) { return (this->i == _rhs.i && this->j == _rhs.j); }
    bool operator !=(cPos _rhs) { return !(this->i == _rhs.i && this->j == _rhs.j); }
    cPos operator -(cPos _rhs) { return cPos(this->i - _rhs.i, this->j - _rhs.j); }
    cPos operator +(cPos _rhs) { return cPos(this->i + _rhs.i, this->j + _rhs.j); }
    cPos operator +(int _rhs) { return cPos(this->i + _rhs, this->j + _rhs); }
    cPos operator *(int _rhs) { return cPos(this->i * _rhs, this->j * _rhs); }
    cPos operator /(int _rhs) { return cPos(this->i / _rhs, this->j / _rhs); }
    FString toString() { return "(" + FString::FromInt(i) + ", " + FString::FromInt(j) + ")"; }
};

/* Enum representing different block types */
enum BlockType { Single, Double, Triple, Full, };

/* Enum representing different tile types */
enum TileType { Plus, T, L, Str8, Full_Tile, };

/* Toolbox class provides helpful static functions for use throughout the entire program */
class Toolbox
{
public:
    static void PRINT(FString _str);
    static void CLEAR_LOG();
    //static UStaticMesh* LOAD_MESH(const TCHAR* _asset);
    static UStaticMesh* GET_RND_MESH_FROM_LIST(TArray<UStaticMesh*> _list);
    static int RND(int _min, int _max);
    static TileType GET_RND_TILETYPE();
};
