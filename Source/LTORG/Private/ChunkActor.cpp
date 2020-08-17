#include "LTORG/Public/ChunkActor.h"

//UStaticMesh* defaultMesh = Toolbox::LOAD_MESH(TEXT("/Game/Meshes/Chunks/Chunk00"));


// Sets default values
AChunkActor::AChunkActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // DISABLED
	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("/Game/StarterContent/Architecture/Floor_400x400"));
	SuperMesh->SetStaticMesh(Asset.Object);
}

// Called when the game starts or when spawned
void AChunkActor::BeginPlay()
{
	Super::BeginPlay();
	SuperMesh->SetStaticMesh(Ass::MESH_CHUNK_00);
	SetActorScale3D(FVector(Nexus::CHUNK_SCALE, Nexus::CHUNK_SCALE, Nexus::CHUNK_SCALE));
}

// Called every frame (DISABLED)
void AChunkActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
