#pragma once
#include "Engine/Engine.h"

class Ass
{
public:
    static UStaticMesh* MESH_EMPTY;
    static UStaticMesh* MESH_BLOCK_SINGLE_DEFAULT;
    static UStaticMesh* MESH_BLOCK_DOUBLE_DEFAULT; 
    static UStaticMesh* MESH_BLOCK_TRIPLE_DEFAULT;
    static UStaticMesh* MESH_BLOCK_FULL_DEFAULT;
    static TArray<UStaticMesh*> MESHLIST_BLOCK_SINGLE;
    static TArray<UStaticMesh*> MESHLIST_BLOCK_DOUBLE;
    static TArray<UStaticMesh*> MESHLIST_BLOCK_TRIPLE;
    static TArray<UStaticMesh*> MESHLIST_BLOCK_FULL;
    static UStaticMesh* MESH_CHUNK_00;
};
