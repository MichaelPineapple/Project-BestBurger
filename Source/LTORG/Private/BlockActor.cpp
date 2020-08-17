#include "LTORG/Public/BlockActor.h"

/*
UStaticMesh* defaultMesh2 = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_Test"));
UStaticMesh* defaultSingleMesh = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_Test"));
UStaticMesh* Mesh_Single_Tall = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Blocks/Single/Block_Single_Tall"));
UStaticMesh* defaultDoubleMesh = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Blocks/Double/Block_Double_Test"));
UStaticMesh* defaultTripleMesh = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Blocks/Triple/Block_Triple_Test"));
UStaticMesh* defaultFullMesh = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Blocks/Full/Block_Full_Test"));
*/


// Sets default values
ABlockActor::ABlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Game/StarterContent/Architecture/Pillar_50x500"));
	SuperMesh->SetStaticMesh(Asset.Object);
}

// Called when the game starts or when spawned
void ABlockActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(Nexus::CHUNK_SCALE, Nexus::CHUNK_SCALE, Nexus::CHUNK_SCALE));
}


// Called every frame (DISABLED)
void ABlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/* Sets the block type. VERY IMPORTANT */
void ABlockActor::setType(BlockType _type)
{
	UStaticMesh* m = Ass::MESH_BLOCK_SINGLE_DEFAULT;
	if (_type == Single) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::MESHLIST_BLOCK_SINGLE);
	else if (_type == Double) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::MESHLIST_BLOCK_DOUBLE);
	else if (_type == Triple) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::MESHLIST_BLOCK_TRIPLE);
	else if (_type == Full) m = Toolbox::GET_RND_MESH_FROM_LIST(Ass::MESHLIST_BLOCK_FULL);
	SuperMesh->SetStaticMesh(m);
}
