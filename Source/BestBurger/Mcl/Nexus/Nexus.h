#pragma once
#include "CoreMinimal.h"
#include "../ToolBox/Toolbox.h"


class BESTBURGER_API Nexus
{
public:
	Nexus();
	~Nexus();
	static void INITIALIZE();
	static void RUN();
	static void UPDATE_PLAYER_POS(FVector _pos);
	static FVector CONVERT_TO_VECTOR(cPos _cPos);
	static cPos CONVERT_TO_CPOS(FVector _vec);
	static AActor* SPAWN_ACTOR(UClass* _bp, FVector _pos, FRotator _rot);
	static UWorld* WORLD;
	const static float CHUNK_SCALE;
	const static float CHUNK_WIDTH;
	const static float CHUNK_HALF_WIDTH;
};
