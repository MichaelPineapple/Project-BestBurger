#pragma once
#include "CoreMinimal.h"
#include "../Nexus/Nexus.h"

class BESTBURGER_API Chunk
{
public:
	Chunk();
	~Chunk();
    Chunk(cPos _cPos);
    void destroy();
    cPos cPosititon;
    FVector realPosition;

private:
    AActor* actor;
    TArray<AActor*> blocksList;
    void addTile(FVector _pos, TileType _type);
    void addBlock(FVector _pos, BlockType _type, float _defaultRotation);
    void addBlock(FVector _pos, BlockType _type);

};
