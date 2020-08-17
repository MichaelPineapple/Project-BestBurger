#include "Toolbox.h"

/* Print a given debug message to the screen */
void Toolbox::PRINT(FString _str)
{
    GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Red, _str);
}

/* Clear debug messages on the screen */
void Toolbox::CLEAR_LOG()
{
    GEngine->ClearOnScreenDebugMessages();
}

/* Returns a random integer between the provided min and max values */
int Toolbox::RND(int _min, int _max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(_min, _max);
    return distr(gen);
}

/* Returns a random 'TileType' */
TileType Toolbox::GET_RND_TILETYPE()
{
    TileType output = Plus;
    switch (RND(0, 4))
    {
        case 0: output = Plus; break;
        case 1: output = T; break;
        case 2: output = L; break;
        case 3: output = Str8; break;
        case 4: output = Full_Tile; break;
    }
    return output;
}

/* Return a random mesh from the gieven 'TArray<UStaticMesh*>' list */
UStaticMesh* Toolbox::GET_RND_MESH_FROM_LIST(TArray<UStaticMesh*> _list)
{
    UStaticMesh* output = nullptr;
    if (_list.Num() > 0) output = _list[Toolbox::RND(0, _list.Num()-1)];
    return output;
}
