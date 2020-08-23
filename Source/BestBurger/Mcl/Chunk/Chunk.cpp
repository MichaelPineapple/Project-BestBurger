#include "Chunk.h"

Chunk::Chunk()
{
}

Chunk::~Chunk()
{
}

/* Caclulate k and b variables based on global chunk size */
float k = Nexus::CHUNK_HALF_WIDTH / 3.0f;
float k3 = Nexus::CHUNK_HALF_WIDTH;
float k5 = 5.0f * k;
float b = k / 2.0f;

/* Array of relative tile locations */
TArray<FVector> tiles = TArray<FVector>(
    {
        FVector(k,k,0),
        FVector(k3,k,0),
        FVector(k5,k,0),

        FVector(k,k3,0),
        FVector(k3,k3,0),
        FVector(k5,k3,0),

        FVector(k,k5,0),
        FVector(k3,k5,0),
        FVector(k5,k5,0),
    });

/* Constructor. Adds a new ChunkActor to the world. Generates tiles */
Chunk::Chunk(cPos _cPos)
{
    this->cPosititon = _cPos;
    this->realPosition = Nexus::CONVERT_TO_VECTOR(cPosititon);
    //this->actor = Nexus::WORLD->SpawnActor<AActor>(Ass::CHUNK_00, realPosition, FRotator(0, 0, 0));
    this->actor = Nexus::SPAWN_ACTOR(Ass::CHUNK_00, realPosition, FRotator(0, 0, 0));
    this->blocksList = TArray<AActor*>();
    for (int i = 0; i < tiles.Num(); i++) addTile(tiles[i], Toolbox::GET_RND_TILETYPE());
}

/* Adds a tile to this chunk with the given positon and type */
void Chunk::addTile(FVector _pos, TileType _type)
{
    float x = _pos.X, y = _pos.Y;
    int rnd = Toolbox::RND(0, 3);
    switch (_type)
    {
    case Plus:
        addBlock(FVector(x + b, y + b, 0), Single);
        addBlock(FVector(x - b, y + b, 0), Single);
        addBlock(FVector(x + b, y - b, 0), Single);
        addBlock(FVector(x - b, y - b, 0), Single);
        break;

    case T:
        if (rnd == 0)
        {
            addBlock(FVector(x, y + b, 0), Double);
            addBlock(FVector(x - b, y - b, 0), Single);
            addBlock(FVector(x + b, y - b, 0), Single);
        }
        else if (rnd == 1)
        {
            addBlock(FVector(x + b, y, 0), Double, 90.0f);
            addBlock(FVector(x - b, y - b, 0), Single);
            addBlock(FVector(x - b, y + b, 0), Single);
        }
        else if (rnd == 2)
        {
            addBlock(FVector(x, y - b, 0), Double, 180.0f);
            addBlock(FVector(x + b, y + b, 0), Single);
            addBlock(FVector(x - b, y + b, 0), Single);
        }
        else if (rnd == 3)
        {
            addBlock(FVector(x - b, y, 0), Double, 270.0f);
            addBlock(FVector(x + b, y + b, 0), Single);
            addBlock(FVector(x + b, y - b, 0), Single);
        }

        break;

    case L:

        if (rnd == 0)
        {
            addBlock(FVector(x + b, y + b, 0), Triple);
            addBlock(FVector(x - b, y - b, 0), Single);
        }
        else if (rnd == 1)
        {
            addBlock(FVector(x + b, y - b, 0), Triple, -90.0f);
            addBlock(FVector(x - b, y + b, 0), Single);
        }
        else if (rnd == 2)
        {
            addBlock(FVector(x - b, y - b, 0), Triple, -180.0f);
            addBlock(FVector(x + b, y + b, 0), Single);
        }
        else if (rnd == 3)
        {
            addBlock(FVector(x - b, y + b, 0), Triple, -270.0f);
            addBlock(FVector(x + b, y - b, 0), Single);
        }

        break;

    case Str8:

        if (rnd == 0 || rnd == 1)
        {
            addBlock(FVector(x, y + b, 0), Double);
            addBlock(FVector(x, y - b, 0), Double);
        }
        else if (rnd == 2 || rnd == 3)
        {
            addBlock(FVector(x + b, y, 0), Double, 90.0f);
            addBlock(FVector(x - b, y, 0), Double, 90.0f);
        }

        break;

    case Full_Tile:
        addBlock(FVector(x, y, 0), Full);
        break;
    }
}


/* Destroy this chunk and all blocks within it */
void Chunk::destroy()
{
    actor->Destroy();
    for (int i = 0; i < blocksList.Num(); i++) blocksList[i]->Destroy();
    blocksList.Empty();
}

/* Add a new block to this chunk */
void Chunk::addBlock(FVector _pos, BlockType _type, float _defaultRotation)
{
    float rotation = _defaultRotation;
    if (_type == Single) rotation = Toolbox::RND(0, 3) * 90.0f;
    else if (_type == Full) rotation = Toolbox::RND(0, 3) * 90.0f;

    UClass* m = Ass::BLOCK_DEFAULT;
    if (_type == Single) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::BLOCK_SINGLE_LIST);
    else if (_type == Double) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::BLOCK_DOUBLE_LIST);
    else if (_type == Triple) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::BLOCK_TRIPLE_LIST);
    else if (_type == Full) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::BLOCK_FULL_LIST);

    //AActor* tmp = Nexus::WORLD->SpawnActor<AActor>(m, realPosition + _pos, FRotator(0.0f, rotation, 0.0f));
    blocksList.Add(Nexus::SPAWN_ACTOR(m, realPosition + _pos, FRotator(0.0f, rotation, 0.0f)));
}
void Chunk::addBlock(FVector _pos, BlockType _type)
{
    addBlock(_pos, _type, 0.0f);
}

