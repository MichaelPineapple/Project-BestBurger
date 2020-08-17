#pragma once
#include "LTORG/Nexus/Nexus.h"
#include "BlockActor.generated.h"

UCLASS()
class ABlockActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void setType(BlockType _type);

private:
    UStaticMeshComponent* SuperMesh;
	
};
