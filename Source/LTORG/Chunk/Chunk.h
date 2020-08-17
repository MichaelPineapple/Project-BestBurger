#pragma once
#include "LTORG/Nexus/Nexus.h"
#include "ChunkActor.h"
#include "LTORG/Public/BlockActor.h"

/* Chunk class represents a single 'Chunk' within the world. Handles generation of tiles and blocks */
class Chunk
{
public:
    Chunk(cPos _cPos);
    void destroy();
    cPos cPosititon;
    FVector realPosition;

private:
    AChunkActor* actor;
    TArray<ABlockActor*> blocksList;
    void addTile(FVector _pos, TileType _type);
    void addBlock(FVector _pos, BlockType _type, float _defaultRotation);
    void addBlock(FVector _pos, BlockType _type);
};
