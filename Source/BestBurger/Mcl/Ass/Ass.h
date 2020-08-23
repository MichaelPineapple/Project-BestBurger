#pragma once
#include "CoreMinimal.h"

class BESTBURGER_API Ass
{
public:
	Ass();
	~Ass();
    static TArray<UClass*> BLOCK_SINGLE_LIST;
    static TArray<UClass*> BLOCK_DOUBLE_LIST;
    static TArray<UClass*> BLOCK_TRIPLE_LIST;
    static TArray<UClass*> BLOCK_FULL_LIST;
    static UClass* CHUNK_00;
    static UClass* BLOCK_DEFAULT;
    static void LOAD_ASSETS();
};
