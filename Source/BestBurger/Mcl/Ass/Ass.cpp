#include "Ass.h"

TArray<UClass*> Ass::BLOCK_SINGLE_LIST;
TArray<UClass*> Ass::BLOCK_DOUBLE_LIST;
TArray<UClass*> Ass::BLOCK_TRIPLE_LIST;
TArray<UClass*> Ass::BLOCK_FULL_LIST;
UClass* Ass::CHUNK_00;
UClass* Ass::BLOCK_DEFAULT;

UClass* LOAD_BLUEPRINT(const TCHAR* _asset)
{
    ConstructorHelpers::FClassFinder<AActor> MyPawnFinder(_asset);
    return (UClass*)MyPawnFinder.Class;
}

void Ass::LOAD_ASSETS()
{
    Ass::CHUNK_00 = LOAD_BLUEPRINT(TEXT("/Game/Blueprints/chunk"));
    Ass::BLOCK_DEFAULT = LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_00"));

    Ass::BLOCK_SINGLE_LIST = TArray<UClass*>(
        {
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_00")),
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_01")),
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_02")),
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_03")),
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_04")),
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_Bank")),
            LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Single/Block_Single_Burger")),
        });

    Ass::BLOCK_DOUBLE_LIST = TArray<UClass*>(
        {
             LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Double/Block_Double_01")),
             LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Double/Block_Double_00")),
        });

    Ass::BLOCK_TRIPLE_LIST = TArray<UClass*>(
        {
             LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Triple/Block_Triple_00")),
             LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Triple/Block_Triple_01")),
        });

    Ass::BLOCK_FULL_LIST = TArray<UClass*>(
        {
             LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Full/Block_Full_00")),
             LOAD_BLUEPRINT(TEXT("/Game/Blueprints/Blocks/Full/Block_Full_01")),
        });
}
