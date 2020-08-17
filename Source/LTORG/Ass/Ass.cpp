#include "Ass.h"

/* Returns the provided mesh asset as a 'UStaticMesh*' pointer (SHOULD ONLY BE USED INSIDE 'Ass') */
UStaticMesh* LOAD_MESH(const TCHAR* _asset)
{
    return LoadObject<UStaticMesh>(NULL, _asset, NULL, LOAD_None, NULL);
}

/* Empty mesh */
UStaticMesh* Ass::MESH_EMPTY = LOAD_MESH(TEXT("/Game/Meshes/EmptyMesh"));
    
/* Default block meshes */
UStaticMesh* Ass::MESH_BLOCK_SINGLE_DEFAULT = LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_Test"));
UStaticMesh* Ass::MESH_BLOCK_DOUBLE_DEFAULT = LOAD_MESH(TEXT("/Game/Meshes/Blocks/Double/Block_Double_Test"));
UStaticMesh* Ass::MESH_BLOCK_TRIPLE_DEFAULT = LOAD_MESH(TEXT("/Game/Meshes/Blocks/Triple/Block_Triple_Test"));
UStaticMesh* Ass::MESH_BLOCK_FULL_DEFAULT = LOAD_MESH(TEXT("/Game/Meshes/Blocks/Full/Block_Full_Test"));


// StaticMesh'/Game/Meshes/Blocks/Full/Block_Full_02.Block_Full_02'

/* Block meshes */
TArray<UStaticMesh*> Ass::MESHLIST_BLOCK_SINGLE = TArray<UStaticMesh*>(
    {
        Ass::MESH_EMPTY,
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_Test")),
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_Tall")),
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_03")),
    });

TArray<UStaticMesh*> Ass::MESHLIST_BLOCK_DOUBLE = TArray<UStaticMesh*>(
    {
        Ass::MESH_EMPTY,
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Double/Block_Double_Test")),
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Double/Block_Double_02")),
    });

TArray<UStaticMesh*> Ass::MESHLIST_BLOCK_TRIPLE = TArray<UStaticMesh*>(
    {
        Ass::MESH_EMPTY,
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Triple/Block_Triple_Test")),
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Triple/Block_Triple_02")),
    });

TArray<UStaticMesh*> Ass::MESHLIST_BLOCK_FULL = TArray<UStaticMesh*>(
    {
        Ass::MESH_EMPTY,
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Full/Block_Full_Test")),
        LOAD_MESH(TEXT("/Game/Meshes/Blocks/Full/Block_Full_02")),
    });

/* Chunk meshes (only one for now) */
UStaticMesh* Ass::MESH_CHUNK_00 = LOAD_MESH(TEXT("/Game/Meshes/Chunks/Chunk00"));

