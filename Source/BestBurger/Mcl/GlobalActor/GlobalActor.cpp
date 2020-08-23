#include "GlobalActor.h"
#include "../Ass/Ass.h"
#include "../Nexus/Nexus.h"

// Sets default values
AGlobalActor::AGlobalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Ass::LOAD_ASSETS();
}

// Called when the game starts or when spawned
void AGlobalActor::BeginPlay()
{
	Super::BeginPlay();
	Nexus::WORLD = GetWorld();
	Nexus::INITIALIZE();
}

// Called every frame
void AGlobalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Nexus::RUN();
}

