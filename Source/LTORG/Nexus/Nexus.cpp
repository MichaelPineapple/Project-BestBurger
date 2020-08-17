#include "Nexus.h"
#include "LTORG/Chunk/Chunk.h"

/* CONSTANTS */
#define DEFAULT_CHUNK_WIDTH 22000
const float Nexus::CHUNK_SCALE = 1.0f;
const float Nexus::CHUNK_WIDTH = DEFAULT_CHUNK_WIDTH * Nexus::CHUNK_SCALE;
const float Nexus::CHUNK_HALF_WIDTH = CHUNK_WIDTH / 2.0f;

/* Global world variable. Assigned by 'GlobalActor' */ 
UWorld* Nexus::WORLD;

/* Player position variables */
FVector playerPosition;
cPos playerCpos;
int playerQuadrant = -1;

/* List of all chunks in the world */
TArray<Chunk> chunkList = TArray<Chunk>();

/* Returns whether a chunk exists at the given cPos */
bool doesChunkExist(cPos _cpos)
{
	bool output = false;
	for (int i = 0; i < chunkList.Num(); i++)
	{
		if (chunkList[i].cPosititon == _cpos) output = true;
	}
	return output;
}

/* Add new chunk at specified cPos */
void addChunk(cPos _cPos)
{
	if (!doesChunkExist(_cPos)) chunkList.Add(Chunk(_cPos));
}

/* Delete Chunk at specified index */
void delChunk(int _index)
{
	chunkList[_index].destroy();
	chunkList.RemoveAt(_index);
}

/* Delete all chunks except the one which the player is standing on */
void clearOuterChunks()
{
	for (int i = chunkList.Num()-1; i >= 0; i--)
	{
		if (chunkList[i].cPosititon != playerCpos) delChunk(i);
	}
}

/* Called whenever the player changes a quadrant */
void onQuadrantChange(int _quad)
{
	//clearOuterChunks();
	
	if (_quad == 1)
	{
		addChunk(playerCpos + cPos(-1, -1));
		addChunk(playerCpos + cPos(-1, 0));
		addChunk(playerCpos + cPos(0, -1));
	}
	else if (_quad == 2)
	{
		addChunk(playerCpos + cPos(1, -1));
		addChunk(playerCpos + cPos(1, 0));
		addChunk(playerCpos + cPos(0, -1));
	}
	else if (_quad == 3)
	{
		addChunk(playerCpos + cPos(-1, 1));
		addChunk(playerCpos + cPos(-1, 0));
		addChunk(playerCpos + cPos(0, 1));
	}
	else if (_quad == 4)
	{
		addChunk(playerCpos + cPos(1, 1));
		addChunk(playerCpos + cPos(1, 0));
		addChunk(playerCpos + cPos(0, 1));
	}
	else
	{
		// wha...?
	}
		
}

/* Main initialization function, called when the game launches. Called by 'GlobalActor' */
void Nexus::INITIALIZE()
{
	Toolbox::PRINT("INIT");
	addChunk(cPos(0,0));
	addChunk(cPos(-1,0));
	addChunk(cPos(0,-1));
	addChunk(cPos(-1,-1));
}

/* Main run function, called every tick. Called by 'GlobalActor' */
void Nexus::RUN()
{
	Toolbox::CLEAR_LOG();
	Toolbox::PRINT(" ");
	Toolbox::PRINT(playerPosition.ToString());
	Toolbox::PRINT(playerCpos.toString());
	Toolbox::PRINT(FString("Quadrant:") + FString::FromInt(playerQuadrant));

	// determine player quadrant
	FVector chunkOrigin = CONVERT_TO_VECTOR(playerCpos);
	int quad = 1;
	if (playerPosition.X > (chunkOrigin.X + CHUNK_HALF_WIDTH)) quad += 1;
	if (playerPosition.Y > (chunkOrigin.Y + CHUNK_HALF_WIDTH)) quad += 2;
	if (quad != playerQuadrant) onQuadrantChange(quad);
	playerQuadrant = quad;
}

/* Update the player's position. Called by the 'Hector' class */
void Nexus::UPDATE_PLAYER_POS(FVector _pos)
{
	playerPosition = _pos;
	playerCpos = CONVERT_TO_CPOS(playerPosition);
}

/* Returns the cPos which contains the given vector positon */
cPos Nexus::CONVERT_TO_CPOS(FVector _pos)
{
	float tmpX = _pos.X;
	float tmpY = _pos.Y;
	if (_pos.X < 0) tmpX -= CHUNK_WIDTH;
	if (_pos.Y < 0) tmpY -= CHUNK_WIDTH;
    return cPos((int)(tmpX / CHUNK_WIDTH), (int)(tmpY / CHUNK_WIDTH));
}

/* Returns the vector positon of the given cPos (origin corner) */
FVector Nexus::CONVERT_TO_VECTOR(cPos _cpos)
{
    return FVector(_cpos.i*CHUNK_WIDTH, _cpos.j*CHUNK_WIDTH, 0);
}