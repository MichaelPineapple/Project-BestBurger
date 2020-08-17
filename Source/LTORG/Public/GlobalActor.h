#pragma once

#include "../Nexus/Nexus.h"
#include "GlobalActor.generated.h"

UCLASS()
class AGlobalActor : public AActor
{
	GENERATED_BODY()
	
public:	
    // Sets default values for this actor's properties
    AGlobalActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
