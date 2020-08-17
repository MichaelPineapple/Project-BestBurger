// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Nexus/Nexus.h"
#include "ChunkActor.generated.h"

UCLASS()
class AChunkActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UStaticMeshComponent* SuperMesh;

};
