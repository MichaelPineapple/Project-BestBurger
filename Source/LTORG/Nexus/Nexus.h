#pragma once

#include "LTORG/ToolBox/Toolbox.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

/* Nexus class is the core of the program */
class Nexus
{
public:
		static void INITIALIZE();
		static void RUN();
		static void UPDATE_PLAYER_POS(FVector _pos);
		static FVector CONVERT_TO_VECTOR(cPos _cPos);
		static cPos CONVERT_TO_CPOS(FVector _vec);
		static UWorld* WORLD;
		const static float CHUNK_SCALE;
		const static float CHUNK_WIDTH;
		const static float CHUNK_HALF_WIDTH;
};
